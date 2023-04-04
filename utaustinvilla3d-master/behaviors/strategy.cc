#include "naobehavior.h"
#include "../rvdraw/rvdraw.h"
#include <algorithm>
extern int agentBodyType;

/*
 * Real game beaming.
 * Filling params x y angle
 */
void NaoBehavior::beam( double& beamX, double& beamY, double& beamAngle ) {
    beamX = -HALF_FIELD_X + worldModel->getUNum();
    beamY = 0;
    beamAngle = 0;
}


SkillType NaoBehavior::selectSkill() {
    VecPosition posBall = worldModel->getBall();
    VecPosition posGoalkp(-15,posBall.getY()/FIELD_Y*GOAL_Y,0);//守门点位
    VecPosition midPoint((posBall+posGoalkp).getX()/2.0,(posBall+posGoalkp).getY()/2.0,0);//中点

    VecPosition ballDir = (posBall-posGoalkp).normalize();//球门指向球的方向单位向量
    VecPosition left90 = VecPosition(0, 0, 1).crossProduct(ballDir)*1.0;
    VecPosition right90 = -VecPosition(0, 0, 1).crossProduct(ballDir)*1.0;

    VecPosition target[6] = {
        posBall + VecPosition(-0.5,0,0),//控球位
        posGoalkp,//守门位
        posBall + VecPosition(9,4,0),//接应位
        posBall + VecPosition(9,-4,0),//接应位
        midPoint + left90*5.0,//防守点
        midPoint + right90*5.0//防守点
    };

    //防止点位越界
    for(int i = 0;i<6;i++){
        if(target[i].getX() >HALF_FIELD_X )
            target[i].setX(HALF_FIELD_X);
        if(target[i].getX() <-HALF_FIELD_X )
            target[i].setX(-HALF_FIELD_X);
        if(target[i].getY() >HALF_FIELD_Y )
            target[i].setY(HALF_FIELD_Y);
        if(target[i].getY() <-HALF_FIELD_Y )
            target[i].setY(-HALF_FIELD_Y);
    }

    vector<vector<double>>dis(6,vector<double>(6,0));
    int BotForTarget[6] = {0};


    for(int i = 0;i<6;i++){ //第i个点位target[i] 
        for(int j = 0;j<6;j++){ //第j名球员
            VecPosition Pos(0,0,0);
            int playerNum = WO_TEAMMATE1 + j;
            WorldObject *tem = worldModel->getWorldObject(playerNum);
            if (worldModel->getUNum() == playerNum)
                    Pos = me;
            else{
                tem = worldModel->getWorldObject(playerNum);
                Pos = tem->pos;
            }
            dis[i][j]=target[i].getDistanceTo(Pos);
        }
    }

    for(int j = 0;j<6;j++){
        int playerNum = WO_TEAMMATE1 + j;
        bool isFallen = worldModel->getFallenTeammate( j );//j√ playerNum×
        if(isFallen) //跌倒花费+1
        {   
           //cout << playerNum <<"isfallen\n";
            for(int i = 0;i<6;i++){
            dis[i][j] += 1.0;
            }
        }
        VecPosition Pos =  worldModel->getWorldObject(playerNum)->pos; //移出场外的球员不考虑
        if(abs(Pos.getX())>HALF_FIELD_X && abs(Pos.getY())>HALF_FIELD_Y){
            for(int i = 0;i<6;i++){
            dis[i][j] = 10000;
            }
        }
        /*
        WorldObject *tem = worldModel->getWorldObject(playerNum); //这个我用不明白，写不好,摆了(；一_一)
        bool isvalid = tem->validPosition;
        if(!isvalid)
        {
            cout << playerNum<<"!valid == true\n";
            for(int i = 0;i<6;i++){
            dis[i][j] = 10000;
            }
        }*/
    }


    for(int i = 0;i<6;i++){ //为点位分配机器人
        int robot = min_element(dis[i].begin(), dis[i].begin() + 6) - dis[i].begin();
        BotForTarget[i] = robot;
        for(int j = 0;j<6;j++)
            dis[j][robot]=10000;
    }

    worldModel->getRVSender()->clearStaticDrawings(); //清屏
    for(int i = 0; i < 6; i++){
    int playerNum = WO_TEAMMATE1 + BotForTarget[i];
    worldModel->getRVSender()->drawPoint(target[i].getX(), target[i].getY(), 10.0f, RVSender::MAGENTA);  //绘制点位
    worldModel->getRVSender()->drawText(to_string(playerNum),target[i].getX(), target[i].getY(), RVSender::MAGENTA);  //绘制点位对应球员号数
    }
    
    //比较获得除了控球机器人自己以外，最近的队友位置，用于禁区内传球
    vector<double>disToKicker(6,0);
    for(int i = 0;i<6;i++){
        VecPosition Pos(0,0,0);
        int playerNum = WO_TEAMMATE1 + BotForTarget[i];
        Pos = worldModel->getWorldObject(playerNum)->pos;
        disToKicker[i] = posBall.getDistanceTo(Pos);
    }
    int iOfClosestTmMate = min_element(disToKicker.begin()+2, disToKicker.begin() + 6) - (disToKicker.begin());//比较距离大小时不考虑自己和守门，不考虑守门是防止乌龙
    VecPosition posClosestTmMate = worldModel->getWorldObject(WO_TEAMMATE1 + BotForTarget[iOfClosestTmMate])->pos;

    for(int i=0;i<6;i++){
        if (worldModel->getUNum() == WO_TEAMMATE1 + BotForTarget[i]){
            if(i == 0)//我是踢球的
            {
                if(me.getDistanceTo(posBall) > 1)//前往持球点
                    return goToTarget(collisionAvoidance(true, false, false, 1,0.5, posBall, true));
                else//我在控球
                {
                    if( me.getX()<(PENALTY_X-HALF_FIELD_X) && abs(me.getY())<(PENALTY_Y/2.0))//禁区内
                        return kickBall(KICK_FORWARD, posClosestTmMate);//踢给最近的队友
                    else if(posBall.getX() < 9)
                    {
                        if(me.getDistanceTo(target[2]) <= me.getDistanceTo(target[3]))
                            return kickBall(KICK_FORWARD, target[2]);//传给接应点的队友
                        else
                            return kickBall(KICK_FORWARD, target[3]);//传给接应点的队友
                    }
                    else
                        return kickBall(KICK_FORWARD, VecPosition(15, 0, 0));
                }
            }
            else//我是去点位的
            return goToTarget(collisionAvoidance(true, false, false, 1, 0.5,target[i], true));
        }
            
    }

    
    // My position and angle
    //cout << worldModel->getUNum() << ": " << worldModel->getMyPosition() << ",\t" << worldModel->getMyAngDeg() << "\n";

    // Position of the ball
    //cout << worldModel->getBall() << "\n";

    // Example usage of the roboviz drawing system and RVSender in rvdraw.cc.
    // Agents draw the position of where they think the ball is
    // Also see example in naobahevior.cc for drawing agent position and
    // orientation.
    /*
    worldModel->getRVSender()->clear(); // erases drawings from previous cycle
    worldModel->getRVSender()->drawPoint("ball", ball.getX(), ball.getY(), 10.0f, RVSender::MAGENTA);
    */

    // ### Demo Behaviors ###

    // Walk in different directions
    //return goToTargetRelative(VecPosition(1,0,0), 0); // Forward
    //return goToTargetRelative(VecPosition(-1,0,0), 0); // Backward
    //return goToTargetRelative(VecPosition(0,1,0), 0); // Left
    //return goToTargetRelative(VecPosition(0,-1,0), 0); // Right
    //return goToTargetRelative(VecPosition(1,1,0), 0); // Diagonal
    //return goToTargetRelative(VecPosition(0,1,0), 90); // Turn counter-clockwise
    //return goToTargetRelative(VecPdosition(0,-1,0), -90); // Turn clockwise
    //return goToTargetRelative(VecPosition(1,0,0), 15); // Circle

    // Walk to the ball
    //return goToTarget(ball);

    // Turn in place to face ball
    /*double distance, angle;
    getTargetDistanceAndAngle(ball, distance, angle);
    if (abs(angle) > 10) {
      return goToTargetRelative(VecPosition(), angle);
    } else {
      return SKILL_STAND;
    }*/

    // Walk to ball while always facing forward
    //return goToTargetRelative(worldModel->g2l(ball), -worldModel->getMyAngDeg());

    // Dribble ball toward opponent's goal
    //return kickBall(KICK_DRIBBLE, VecPosition(HALF_FIELD_X, 0, 0));

    // Kick ball toward opponent's goal
    //return kickBall(KICK_FORWARD, VecPosition(HALF_FIELD_X, 0, 0)); // Basic kick
    //return kickBall(KICK_IK, VecPosition(HALF_FIELD_X, 0, 0)); // IK kick

    // Just stand in place
    //return SKILL_STAND;

    // Demo behavior where players form a rotating circle and kick the ball
    // back and forth
    return demoKickingCircle();
}


/*
 * Demo behavior where players form a rotating circle and kick the ball
 * back and forth
 */
SkillType NaoBehavior::demoKickingCircle() {
    // Parameters for circle
    VecPosition center = VecPosition(-HALF_FIELD_X/2.0, 0, 0);
    double circleRadius = 5.0;
    double rotateRate = 2.5;

    // Find closest player to ball
    int playerClosestToBall = -1;
    double closestDistanceToBall = 10000;
    for(int i = WO_TEAMMATE1; i < WO_TEAMMATE1+NUM_AGENTS; ++i) {
        VecPosition temp;
        int playerNum = i - WO_TEAMMATE1 + 1;
        if (worldModel->getUNum() == playerNum) {
            // This is us
            temp = worldModel->getMyPosition();
        } else {
            WorldObject* teammate = worldModel->getWorldObject( i );
            if (teammate->validPosition) {
                temp = teammate->pos;
            } else {
                continue;
            }
        }
        temp.setZ(0);

        double distanceToBall = temp.getDistanceTo(ball);
        if (distanceToBall < closestDistanceToBall) {
            playerClosestToBall = playerNum;
            closestDistanceToBall = distanceToBall;
        }
    }

    if (playerClosestToBall == worldModel->getUNum()) {
        // Have closest player kick the ball toward the center
        return kickBall(KICK_FORWARD, center);
    } else {
        // Move to circle position around center and face the center
        VecPosition localCenter = worldModel->g2l(center);
        SIM::AngDeg localCenterAngle = atan2Deg(localCenter.getY(), localCenter.getX());

        // Our desired target position on the circle
        // Compute target based on uniform number, rotate rate, and time
        VecPosition target = center + VecPosition(circleRadius,0,0).rotateAboutZ(360.0/(NUM_AGENTS-1)*(worldModel->getUNum()-(worldModel->getUNum() > playerClosestToBall ? 1 : 0)) + worldModel->getTime()*rotateRate);

        // Adjust target to not be too close to teammates or the ball
        target = collisionAvoidance(true /*teammate*/, false/*opponent*/, true/*ball*/, 1/*proximity thresh*/, .5/*collision thresh*/, target, true/*keepDistance*/);

        if (me.getDistanceTo(target) < .25 && abs(localCenterAngle) <= 10) {
            // Close enough to desired position and orientation so just stand
            return SKILL_STAND;
        } else if (me.getDistanceTo(target) < .5) {
            // Close to desired position so start turning to face center
            return goToTargetRelative(worldModel->g2l(target), localCenterAngle);
        } else {
            // Move toward target location
            return goToTarget(target);
        }
    }
}


