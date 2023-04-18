#include <iostream>
#include "SingleLinkedList.h"

int main(){
	int i=100;
	int k;
	elementType x;
while (i != -999)
	{
		node *L,*L1,*L2,*L3;
		mymenu();
		cin>>i;
		switch (i)
		{
		case 0:
			exit(0);
		case 1:
			creatList(&L);
			break;
		case 2:
			initialList(&L);
			cout<<"链表已初始化";
			break; 
		case 3:
			cout<<"链表元素为： "<<endl;
			outPut(&L);
			break;
	    case 4:
	    	cout<<"请输入你想插入的元素位置"<<endl;
	    	cin>>k;
	    	cout<<"请输入你想插入的元素"<<endl;
	    	cin>>x;
	        listInsert(L,k,x);
	        outPut(&L);
	        break; 
	    case 5:
	    	cout<<"请输入你想删除的元素位置"<<endl;
	    	cin>>k;
	    	listDelete(L,k);
	    	outPut(&L);
	    	break;
	    case 6:
	    	cout<<"在递增有序的单链表L中插入一个值为x的元素，请输入你想插入的元素："<<endl;
	    	cin>>x;
	    	uplistInsert(L,x);
	    	break;
	    case 7:
	        cout<<"执行分开奇偶数：\n";
	        listSeperate(L);
			break; 
	    case 8:
	        initialList(&L1);
	        creatList(&L1);
	        cout << endl;
	        initialList(&L2);
	        creatList(&L2);
	        initialList(&L3);
	        getListRep(L1, L2, L3);
	        cout << endl;
	        cout << "含L1和L2中公共元素的新表L3为：";
	        outPut(&L3);
	        break;
	    case 9:
	    	upListRepDelete(L);
	    	outPut(&L);
			break;
	    case 10:
			initialList(&L1);
	        creatList(&L1);
	        cout << endl;
	        initialList(&L2);
	        creatList(&L2);
		    listAddList(L1,L2);
			outPut(&L1);
		}
	    system("PAUSE");
        system("CLS");
	}
}
