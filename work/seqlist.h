#include <iostream>
#define MAXLEN 100

using namespace std;

typedef int elementType;
struct sList{
	elementType data[MAXLEN] ;
	int listLen ;
};

typedef struct sList seqList;

//�������� 
void creatlist(seqList* L) {
	int i = 0;
	cin >> i;
	while (i != -1)
	{
		L->data[L->listLen] = i;
		L->listLen++;
		cin >> i;
	}
	cout<<"��Ϊ"<<L->listLen<<endl; 

}
//��ʼ��
void initialList(seqList *L){
	L->listLen = 0;
}

//���ر�
int listLength(seqList L){
	return L.listLen;
}

//ȡ��ָ��Ԫ��
bool getElement(seqList L, int i, elementType * x){
	if(i<1 || i>L.listLen)
		return 1;
	else
	{
		(*x) = L.data[i-1];
		return 0;
	}
}

//�������Ԫ��
bool listInsert(seqList *L, elementType x, int i)
{
	int j;
	if(L->listLen == MAXLEN)
		return  1;
	else if(i<1|| i>L->listLen + 1)
		return 1;
	else
	{
	  for(j=L->listLen-1;j>=i-1;j--)
    	{
		L->data[j+1]=L->data[j];//˳���i�����Ԫ�غ���һλ 
		}
	  L->data[i-1] = x;
	  L->listLen++;
      return 0;
	}
} 


//����˳������
bool uplistInsert(seqList *L, elementType x)
{
	int i;
	if(L->listLen == MAXLEN)
		return  1;
	else
	{
	  for(i=0;L->data[i]<x;)
	  {
		  i++; 
	  }
	if(listInsert(L,x,i+1))
		return 1;
	else
		return 0;
	} 
}

//ɾ��ָ��Ԫ��
int listDelete(seqList * L, int i){ 
	if(L->listLen<=0)
		return 0;
	else if(i<1 || i>L->listLen)
		return 1;
	else
	{
	int j;
	for(j=i; j<L->listLen; j++ )
		L->data[j-1]=L->data[j];
		L->listLen--;
		return 2;
	}
}

//ɾ���ظ�Ԫ��
void listRepDelete(seqList * L){
	for(int i = 0; i<L->listLen-1; ){
		if (L->data[i] == L->data[i+1])
			listDelete(L,i+1);
		else i++;
	}
}

//������� 
void outPut(seqList* L){
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		cout << "["<< L->data[i] << "] ";
	}
	cout << endl;
}

//�����ż
 void listseparate(seqList* L,seqList* Lj,seqList* Lo)
 {
 	int i=0,j=0,k=0;
 	for(i=0;i<L->listLen;i++)
 	{
 		if(L->data[i]%2==0)
 		{
 			Lo->data[j]=L->data[i];
 			Lo->listLen++;
 			j++;
		 }
		 if(L->data[i]%2==1)
		 {
		 	Lj->data[k]=L->data[i];
		 	Lj->listLen++;
		 	k++;
		 }
		 
	 }
  } 

void deletelistreapt(seqList* L,int* count)
  {
	*count = 0; //ͳ���ƶ�Ԫ�ش���
	int p = L->listLen-1;//p���±꣬q 
	int q = L->listLen;   //p��i���ִ��listlen-1�Σ�����i-1���±��ܱ�����1֮ǰ���� 
	for (int i = 1; i < q; i++)//��ΪL->listlen��仯���Եü�¼���� 
	{
		if (L->data[p] == L->data[p - 1])
		{
			listDelete(L, p + 1);
			*count += L->listLen - p;
		}
		p--; 
	}
  }
//
void RelativeComplement(seqList * A,seqList * B){
	int i=0,j=0;
	while(i<A->listLen&&j<B->listLen){
		if(A->data[i] < B->data[j])
			++i;
		else if(A->data[i] > B->data[j])
			++j;
		else if(A->data[i] == B->data[j])
			listDelete(A,i);
	}
} 
void mymenu()
{
	cout << "+��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������+" << endl;
	cout << "|    ����0��-1�˳�����                                                                   |" << endl;
	cout << "|    ����1����Ԫ��                                                                       |" << endl;
	cout << "|    ����2ɾ����i��λ��Ԫ��                                                              |" << endl;
	cout << "|    ����3��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�           |" << endl;
	cout << "|    ����4��˳�����е��������ż������ֽ⿪                                         |" << endl;
	cout << "|    ����5��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��                     |" << endl;
	cout << "|    ����6ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش���                             |" << endl;
	cout << "|   *����7��������   *                                                                       |" << endl;
	cout << "|   *����8��ʼ������ *                                                                     |" << endl;
	cout << "|   *����9��ʾ����   *                                                                 |" << endl;
	cout << "+��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������+" << endl;
}
/*
int main(){
	seqList L;
	seqList M;
	M.data[0] = 1;
	M.data[1] = 5;
	M.data[2] = 21;
	M.listLen = 3;
	RelativeComplement(&L,&M);
	for(int i = 0;i<L.listLen;i++)
	cout << L.data[i];
	
	return 0;
}
*/