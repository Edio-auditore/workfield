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
			cout << "����������λ��" << endl;
			cin >> j;
			cout << "���������Ԫ�أ�" << endl;
			cin >> x;
			if (listInsert(&L, x, j))
			{
                cout << "���󣺱�����" << endl;
			}
			else
			{
				cout << "������˳���" << endl;
				outPut(&L);
			}
			break;
		case 2:
			cout << "������Ҫɾ����Ԫ��λ��" << endl;
			cin >> j;
			if (listDelete(&L, j)!=2)
			{
                cout << "����"<<(listDelete(&L, j) == 0)? "�ձ�":"��Ԫ��λ�ò�����Ч��Χ��";
			}
			else
			{
				cout << "ɾ��Ԫ�ص�����Ϊ" << endl;
				outPut(&L);
			}
			break;
		case 3:
			cout << "ԭ��" << endl;
			outPut(&L);
			cout << "����������Ԫ�أ�" << endl;
			cin >> x;
			uplistInsert(&L, x);
			cout << "����Ԫ�غ������" << endl;
			outPut(&L);
			break;
		case 4:
			initialList(&Lj);
			initialList(&Lo);//��ʼ��Lj��Lo
			cout<<"ԭ��Ϊ";
			outPut(&L);
			listseparate(&L,&Lj,&Lo);
			cout<<"������Ϊ:"<<endl;
			outPut(&Lj); 
			cout<<"ż����Ϊ:"<<endl;
			outPut(&Lo); 
			break;
		case 5:
			/*initialList(&Lj);
			initialList(&Lo);
			initialList(&L1);//��ʼ��������
			cout<<"�����������1������-1������"<<endl;
			creatlist(&Lj);
			cout<<"�����������2������-1������"<<endl;
			creatlist(&Lo);
			listcommon(&Lj,&Lo,&L1);
			outPut(&Lj);
			outPut(&Lo);
			cout<<"��3Ϊ��ͬ��Ԫ��:"<<endl; 
			outPut(&L1);*/
			break;
		case 6:
			cout<<"ԭ��Ϊ:"<<endl;
			int count = 0;
			outPut(&L);
			deletelistreapt(&L,&count);
			cout <<"�����:"<<endl;
			outPut(&L); 
			cout <<"�ƶ�Ԫ�ش���Ϊ:"<< count;
			break;
		case 7:
			cout << "������˳���L���ݣ�" << endl;
			creatlist(&L);
			cout << "���ݳɹ�¼��" << endl;
			break;
		case 8:
			initialList(&L);
			cout << "\n��ʼ��\n" << endl;
			break;
		case 9:
			cout << "����Ϊ��";
			outPut(&L);
		}
		system("pause");
		system("cls");
	}
	
	
}
