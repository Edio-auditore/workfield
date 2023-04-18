#include <iostream>

using namespace std;

typedef int elementType;



struct slNode{
	elementType data;
	slNode *next;
};
typedef struct slNode node,*linkList;
void mymenu()
{
	cout << "+---------------------------------------------------------------------------------+" << endl;
	cout << "|    ����-999���˳�����                                                           |" << endl;
	cout << "|   *����1��������   *                                                            |" << endl;
	cout << "|   *����2��ʼ������ *                                                            |" << endl;
	cout << "|   *����3��ʾ����   *                                                            |" << endl;
	cout << "|    ����4����Ԫ��                                                                |" << endl;
	cout << "|    ����5ɾ����i��λ��Ԫ��                                                       |" << endl;
	cout << "|    ����6��һ���������������L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�      |" << endl;
	cout << "|    ����7��������е��������ż������ֽ⿪                                    |" << endl;
	cout << "|    ����8������������������L1��L2�еĹ���Ԫ�أ������µ�����L3��                  |" << endl;
	cout << "|    ����9ɾ���������������е��ظ�Ԫ��                                            |" << endl;
	cout << "|    ����10�ϲ���������L1��L2                                                     |" << endl;
	cout << "+---------------------------------------------------------------------------------+" << endl;
}


void initialList(node * *L){
	*L = new node;
	(*L)->next = NULL;
}

/*
void outPut(node** L) 
{
	node *p;
	p=(*L)->next;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
*/

void outPut(node **L) {
	if((*L)->next == NULL)
	{
		cout <<"���󣬿ձ�"<<endl;
		return; 
	}
	node *p = (*L)->next;
	while(p != NULL)
	{
		cout <<"["<<p->data<<"] ";
		p =p->next;
	}
	}

void creatList(node* *L)
{
    elementType x;
    node * u,*R;
    *L=new node;    //����ͷ���
    initialList(L);
    R = *L;
    cout<<"��-999����������������Ԫ�أ�"<<endl;
    cin>>x;
    while(x!=-999)
    {
        u=new node;    
        u->data=x;
		u->next = NULL;
        R->next=u;               //β�巨
        R=u;
        cin>>x;
    }
    cout<<"����Ϊ��";
    outPut(L);
}

void killList(node **L)
{
    node *p,*q;
    p=*L;          //��ʼ��ʱpָ��ͷ���
    while(p!=NULL) //p��Ϊ��ʱִ��
    {
        q=p->next; //q������¼p����һ���ڵ�
        delete p;  //�ͷ�p���
        p=q;       //��q��ֵ��p
    }
    
}

int listLength(node * L){
	int len = 0; node * p = L->next;
	while(p != NULL)
	{
		len++;
		p=p->next;
	}
	return len;
}

int listInsert(node* L,int i,elementType x)
{
	node *p=L;//pָ��L 
	node *u;//S���ڴ���һ���µĽڵ� 
	int j=0;
  	while(j!=i-1&&p!=NULL)
  	{
  		p=p->next;
		j++; 
	}
	
	if(p==NULL)
	{
	  cout<<"������Χ"<<endl;
	  return 1;
    }
	else
	{
		u=new node;
		u->data=x;
		u->next=p->next;//���Ӻ�һ����� 
		p->next=u;//����ǰһ����� 
	}
	return 0;
}

void uplistInsert(node*L,elementType x)
{
	node* u;
	node *p=L;
	int i=1;
	while(p->next!=NULL&&p->next->data<x)
	{
			p=p->next;	
	}
	if(p->next==NULL||p->next->data>=x)
	{
		u=new node;
		u->data=x;
		u->next=p->next;
		p->next=u;
	}
	outPut(&L);
} 

node * getElement( node * L, int i )
{
	node *p = L->next; int j = 1;
	while( j!=i && p != NULL )
	{
		j++;
		p = p->next;
		
	}
	return p;
}

node * listLocate (node * L, elementType x)
{
	node * p = L->next;
	while(p!=NULL && p->data!=x)
	{
		p = p->next;
	}
	return p;
}

int listDelete(node *L, int i)
{
	node *p, *u;
	int j = 0;
	p=L;
	while(j != i-1 && p!=NULL)
	{
		p=p->next;
		j++;
	}
	if(p==NULL||p->next==NULL)
	{
		cout<<"������Χ"<<endl;
		return 1;
    }
    else
	{
	u=p->next;
	p->next=u->next;
	delete u;	
	}        
	return 0;
} 

void listSeperate(node *L)
{
	node *p;
    node *L1,*L2,*M,*N,*u;
    p= L->next;                      //��ʼ��ʱpָ��ͷ���L
    L1=new node;                       //����ͷָ��L1
    L2=new node;                       //����ͷָ��L2
    
    initialList(&L1);                  //��ʼ��L1
    initialList(&L2);                  //��ʼ��L2
	M=L1;                              //��ʼ��ʱMָ��ͷ���L1
    N=L2;                              //��ʼ��ʱNָ��ͷ���L2
    while(p!=NULL)                     //�������Ϊ�գ�����ִ��
    {
        if(p->data%2==0)               //�����ż������������L1
        {
            u=new node;                //�����½��
            u->data=p->data;           //����β�巨����������
            u->next=M->next;
            M->next=u;
            M=u;
        }
        else{                          //�������������������L2
            u=new node;                //�����½��
            u->data=p->data;           //����β�巨����������
            u->next=N->next;
            N->next=u;
            N=u;
        }
        p=p->next;                     //p����һλ
    }
    cout<<"ż����L1Ϊ��";
	outPut(&L1);
	cout<<"\n������L2Ϊ��";
    outPut(&L2);                        //��ӡ����L2
    killList(&L1);                  //��������L1
    killList(&L2);           
}

void getListRep(linkList&L1,linkList&L2,linkList&L3)
{
	node * p1, * p2, * p3;
	node* q;
	p1 = L1->next;
	p2 = L2->next;
	p3 = L3;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data == p2->data)
		{
			q = new node;
			q->data = p1->data;
			q->next = NULL;
			p3->next = q;
			p3 = p3->next;  //�±��ָ�����һ��

			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->data < p2->data)
		{
			p1 = p1->next;
		}
		else if (p1->data > p2->data)
		{
			p2 = p2->next;
		}
	} 
}

void upListRepDelete(linkList L)
{
	node *p,*q;
    q = L->next;
    if(q==NULL)
        cout<<"����"; 
    p = q->next;
    while(p!=NULL)
    {
        if((p->data)-(q->data)>0)
        {
            q=p;//�൱��q+1 
            p=p->next;//�൱��p+1 
        }
        else if((p->data)-(q->data)==0)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }
    }
}


void xListDelete(node *L, elementType x){
	node *p,*u;
	p = L;
	while(p != NULL && p->next != NULL){
		if(p->next->data == x)
		{
			u = p->next;
			p ->next= u->next;
			delete u;
			continue;
		}
		p = p->next; 
	}
	return ;
}

void listAddList(node *A,node *B)
{
	node *o = A;
	node *p = A->next;
	node *q = B->next;
	while(p != NULL && q != NULL)
	if(p->data > q->data)
	{
		o->next = q;
		o = o->next;
		q = q->next;
	}
	else if(p->data < q->data)
	{
		o->next = p;
		o = o->next;
		p = p->next;
	}
	else if(p->data == q->data)
	{
		o->next = p;
		o = o->next;
		p = p->next;
	}
	if(p == NULL)
	{
		o->next = q;
	}else if(q == NULL)
	{
		o->next = p;
	}
}
 
