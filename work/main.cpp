#include <iostream>
#include "linkedStack.h"
using namespace std;

void test01();
void test02();
void test03();

int main(){
	int i;   //ѡ�����i
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
	cout << "������Ҫת�������֣�" ;
	cin >> num;
	cout << "������Ҫת���Ľ��ƣ�";
	cin >> x;
	if(x > 36 || x < 2){
		cout << "���󣺽��������Ϸ�";
	}
	sNode *S;
	S = numTrans(num , x);
	cout << "����ת���Ľ��Ϊ��";
	popAll(S);
}

void test02(){
	string s;
	cout << "��������ѧ���ʽ��";
	cin >> s;
	if(bracketMatch2Linked(s)){
		cout << "����ѧ���ʽ�Ϸ�";
	} 
	else{
		cout << "����ѧ���ʽ���Ϸ�";
	}
}

void test03(){
	int n;
	cout << "������n�Ĵ�С��";
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









