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
			cout<<"�����ѳ�ʼ��";
			break; 
		case 3:
			cout<<"����Ԫ��Ϊ�� "<<endl;
			outPut(&L);
			break;
	    case 4:
	    	cout<<"��������������Ԫ��λ��"<<endl;
	    	cin>>k;
	    	cout<<"��������������Ԫ��"<<endl;
	    	cin>>x;
	        listInsert(L,k,x);
	        outPut(&L);
	        break; 
	    case 5:
	    	cout<<"����������ɾ����Ԫ��λ��"<<endl;
	    	cin>>k;
	    	listDelete(L,k);
	    	outPut(&L);
	    	break;
	    case 6:
	    	cout<<"�ڵ�������ĵ�����L�в���һ��ֵΪx��Ԫ�أ���������������Ԫ�أ�"<<endl;
	    	cin>>x;
	    	uplistInsert(L,x);
	    	break;
	    case 7:
	        cout<<"ִ�зֿ���ż����\n";
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
	        cout << "��L1��L2�й���Ԫ�ص��±�L3Ϊ��";
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
