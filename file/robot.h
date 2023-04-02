#include <iostream>
#include <string>
using namespace std;

class behavior {  //基本机器人
protected:
    string name = "null";

public:
    /* ----- Your Code Here ----- */
    behavior(string inName) : name(inName) {}
    virtual ~behavior() {}
    virtual void action() {} 
    /* ----- Your Code Here ----- */
};

class walkBehavior : public behavior //走路机器人
{
public:
    /* ----- Your Code Here ----- */
    walkBehavior(string inName) : behavior(inName) {}
    virtual ~walkBehavior() {}
    void action(){
        cout <<"My name is "<< name << ", I'm walking!\n";
    }
    /* ----- Your Code Here ----- */
};

class runBehavior : public behavior //跑步机器人
{
public:
    /* ----- Your Code Here ----- */
    runBehavior(string inName) : behavior(inName) {}
    virtual ~runBehavior() {}
    void action(){
        cout <<"My name is "<< name << ", I'm running!\n";
    }
    /* ----- Your Code Here ----- */
};

/*
class wxjBehavior : public walkBehavior, public runBehavior //健全机器人
{
public:
    // ----- Your Code Here -----
    wxjBehavior(string inName) : runBehavior(inName), walkBehavior(inName) {}
    void action() {
        cout <<"My name is "<< runBehavior::name << ", I'm walking and running!\n";
    }
    该机器人类继承存在的问题：  1.基类behavior的数据成员name重复了，wxjBehavior类的父类runBehavior和父类walkBehavior中都有一个来自behavior的name属性，
                                造成了路径二义性问题，会提示变量不明确,标明作用域(runBehavior::name)解决后仍然有浪费存储空间的问题。
                              2.不能使用test_behavior = new wxjBehavior("wxj")一类的操作，即无法使用基类behavior型的指针指向派生类wxjBehavior型的对
                                象，会提示基类不明确。因为wxjBehavior中包含两个behavior基类，分别来自runBehavior和walkBehavior，基类指针不知道该
                                指向哪个基类behavior。
                             解决方案：引入虚继承，在定义runBehavior和walkBehavior继承behavior时，在继承方式前加上 virtual，即把behavior设置成虚基类，
                             然后在wxjBehavior的构造函数后面加上Behavior(inName)。生成的wxjBehavior型对象在内存中的name数据成员只有一个，包含的基类behavior
                             也只有一个。此时调用name不需要标明作用域，也可以正常使用behavior型的指针指向wxjBehavior型的对象并调用其成员。
    // ----- Your Code Here -----
};
*/
