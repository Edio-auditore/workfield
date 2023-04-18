#include <iostream>
#define MAXLEN 100

using namespace std;

typedef int elementType;
struct sList{
	elementType data[MAXLEN] ;
	int listLen ;
};

typedef struct sList seqList;

//创建链表 
void creatlist(seqList* L) {
	int i = 0;
	cin >> i;
	while (i != -1)
	{
		L->data[L->listLen] = i;
		L->listLen++;
		cin >> i;
	}
	cout<<"表长为"<<L->listLen<<endl; 

}
//初始化
void initialList(seqList *L){
	L->listLen = 0;
}

//返回表长
int listLength(seqList L){
	return L.listLen;
}

//取出指定元素
bool getElement(seqList L, int i, elementType * x){
	if(i<1 || i>L.listLen)
		return 1;
	else
	{
		(*x) = L.data[i-1];
		return 0;
	}
}

//插入给定元素
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
		L->data[j+1]=L->data[j];//顺序表i后面的元素后移一位 
		}
	  L->data[i-1] = x;
	  L->listLen++;
      return 0;
	}
} 


//递增顺序表插入
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

//删除指定元素
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

//删除重复元素
void listRepDelete(seqList * L){
	for(int i = 0; i<L->listLen-1; ){
		if (L->data[i] == L->data[i+1])
			listDelete(L,i+1);
		else i++;
	}
}

//输出链表 
void outPut(seqList* L){
	int i;
	for (i = 0; i < L->listLen; i++)
	{
		cout << "["<< L->data[i] << "] ";
	}
	cout << endl;
}

//表分奇偶
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
	*count = 0; //统计移动元素次数
	int p = L->listLen-1;//p是下标，q 
	int q = L->listLen;   //p与i配合执行listlen-1次，这样i-1的下标能保持在1之前结束 
	for (int i = 1; i < q; i++)//因为L->listlen会变化所以得记录下来 
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
	cout << "+————————————————————————————————————————————————————————————————————————————————————————+" << endl;
	cout << "|    输入0或-1退出程序                                                                   |" << endl;
	cout << "|    输入1插入元素                                                                       |" << endl;
	cout << "|    输入2删除第i个位置元素                                                              |" << endl;
	cout << "|    输入3在一个递增有序的顺序表L中插入一个值为x的元素，并保持其递增有序特性。           |" << endl;
	cout << "|    输入4将顺序表Ｌ中的奇数项和偶数项结点分解开                                         |" << endl;
	cout << "|    输入5求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中                     |" << endl;
	cout << "|    输入6删除递增有序顺序表中的重复元素，并统计移动元素次数                             |" << endl;
	cout << "|   *输入7创建链表   *                                                                       |" << endl;
	cout << "|   *输入8初始化链表 *                                                                     |" << endl;
	cout << "|   *输入9显示链表   *                                                                 |" << endl;
	cout << "+————————————————————————————————————————————————————————————————————————————————————————+" << endl;
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