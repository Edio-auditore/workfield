#include <iostream>
#include "linkedStack.h"
using namespace std;

void test01();
void test02();
void test03();

int main(){
	int i;   //选择序号i
	do{
		mymenu();
	cin >> i;

	switch (i)
	{
		case 1:
			test01();
			break;
		case 2:
			test02();
			break;
		case 3:
			test03();
			break;
		case 4:
			return 0;
	}
		system("pause");
		system("cls");
	} while(i != 4);
} 

void test01(){
	int x, num;
	cout << "请输入要转换的数字：" ;
	cin >> num;
	cout << "请输入要转换的进制：";
	cin >> x;
	if(x > 36 || x < 2){
		cout << "错误：进制数不合法";
	}
	sNode *S;
	S = numTrans(num , x);
	cout << "进制转换的结果为：";
	popAll(S);
}

void test02(){
	string s;
	cout << "请输入数学表达式：";
	cin >> s;
	if(bracketMatch2Linked(s)){
		cout << "该数学表达式合法";
	} 
	else{
		cout << "该数学表达式不合法";
	}
}

void test03(){
	int n;
	cout << "请输入n的大小：";
	cin >> n;
	sNode *top;
	int In[100];
	for(int i = 0 ; i < n ; i++){
		In[i] = i + 1;
	}
	int Out[100];
	initialStack(top);
	legalSequenceLinked(top , In , Out , n , 0 , 0);
	system("pause");
}









