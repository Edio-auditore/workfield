#include <iostream>
#include "seqlist.h"

int main(){
	sList L,Lj,Lo,L1;
	int j,i=100;
	elementType x;
	initialList(&L);
	initialList(&Lj);
	initialList(&Lo);
	initialList(&L1);
	while (i != -1)
	{
		mymenu();
		cin >> i;
		switch (i)
		{
		case 0:
			exit(0);
		case 1:
			cout << "请输入插入的位置" << endl;
			cin >> j;
			cout << "请输入插入元素：" << endl;
			cin >> x;
			if (listInsert(&L, x, j))
			{
                cout << "错误：表已满" << endl;
			}
			else
			{
				cout << "插入后的顺序表" << endl;
				outPut(&L);
			}
			break;
		case 2:
			cout << "请输入要删除的元素位置" << endl;
			cin >> j;
			if (listDelete(&L, j)!=2)
			{
                cout << "错误："<<(listDelete(&L, j) == 0)? "空表":"该元素位置不在有效范围内";
			}
			else
			{
				cout << "删除元素的链表为" << endl;
				outPut(&L);
			}
			break;
		case 3:
			cout << "原表：" << endl;
			outPut(&L);
			cout << "请输入插入的元素：" << endl;
			cin >> x;
			uplistInsert(&L, x);
			cout << "插入元素后的链表：" << endl;
			outPut(&L);
			break;
		case 4:
			initialList(&Lj);
			initialList(&Lo);//初始化Lj和Lo
			cout<<"原表为";
			outPut(&L);
			listseparate(&L,&Lj,&Lo);
			cout<<"奇数表为:"<<endl;
			outPut(&Lj); 
			cout<<"偶数表为:"<<endl;
			outPut(&Lo); 
			break;
		case 5:
			/*initialList(&Lj);
			initialList(&Lo);
			initialList(&L1);//初始化三个表
			cout<<"请输入递增表1（输入-1结束）"<<endl;
			creatlist(&Lj);
			cout<<"请输入递增表2（输入-1结束）"<<endl;
			creatlist(&Lo);
			listcommon(&Lj,&Lo,&L1);
			outPut(&Lj);
			outPut(&Lo);
			cout<<"表3为相同的元素:"<<endl; 
			outPut(&L1);*/
			break;
		case 6:
			cout<<"原表为:"<<endl;
			int count = 0;
			outPut(&L);
			deletelistreapt(&L,&count);
			cout <<"处理后:"<<endl;
			outPut(&L); 
			cout <<"移动元素次数为:"<< count;
			break;
		case 7:
			cout << "请输入顺序表L数据：" << endl;
			creatlist(&L);
			cout << "数据成功录入" << endl;
			break;
		case 8:
			initialList(&L);
			cout << "\n初始化\n" << endl;
			break;
		case 9:
			cout << "链表为：";
			outPut(&L);
		}
		system("pause");
		system("cls");
	}
	
	
}
