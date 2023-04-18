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
	cout << "|    输入-999以退出程序                                                           |" << endl;
	cout << "|   *输入1创建链表   *                                                            |" << endl;
	cout << "|   *输入2初始化链表 *                                                            |" << endl;
	cout << "|   *输入3显示链表   *                                                            |" << endl;
	cout << "|    输入4插入元素                                                                |" << endl;
	cout << "|    输入5删除第i个位置元素                                                       |" << endl;
	cout << "|    输入6在一个递增有序的链表L中插入一个值为x的元素，并保持其递增有序特性。      |" << endl;
	cout << "|    输入7将链表Ｌ中的奇数项和偶数项结点分解开                                    |" << endl;
	cout << "|    输入8求两个递增有序链表L1和L2中的公共元素，放入新的链表L3中                  |" << endl;
	cout << "|    输入9删除递增有序链表中的重复元素                                            |" << endl;
	cout << "|    输入10合并递增链表L1和L2                                                     |" << endl;
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
		cout <<"错误，空表"<<endl;
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
    *L=new node;    //创建头结点
    initialList(L);
    R = *L;
    cout<<"按-999结束，请输入链表元素："<<endl;
    cin>>x;
    while(x!=-999)
    {
        u=new node;    
        u->data=x;
		u->next = NULL;
        R->next=u;               //尾插法
        R=u;
        cin>>x;
    }
    cout<<"链表为：";
    outPut(L);
}

void killList(node **L)
{
    node *p,*q;
    p=*L;          //初始化时p指向头结点
    while(p!=NULL) //p不为空时执行
    {
        q=p->next; //q变量记录p的下一个节点
        delete p;  //释放p结点
        p=q;       //把q赋值给p
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
	node *p=L;//p指向L 
	node *u;//S用于创造一个新的节点 
	int j=0;
  	while(j!=i-1&&p!=NULL)
  	{
  		p=p->next;
		j++; 
	}
	
	if(p==NULL)
	{
	  cout<<"超出范围"<<endl;
	  return 1;
    }
	else
	{
		u=new node;
		u->data=x;
		u->next=p->next;//连接后一个结点 
		p->next=u;//连接前一个结点 
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
		cout<<"超出范围"<<endl;
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
    p= L->next;                      //初始化时p指向头结点L
    L1=new node;                       //生成头指针L1
    L2=new node;                       //生成头指针L2
    
    initialList(&L1);                  //初始化L1
    initialList(&L2);                  //初始化L2
	M=L1;                              //初始化时M指向头结点L1
    N=L2;                              //初始化时N指向头结点L2
    while(p!=NULL)                     //如果链表不为空，继续执行
    {
        if(p->data%2==0)               //如果是偶数，插入链表L1
        {
            u=new node;                //创建新结点
            u->data=p->data;           //采用尾插法，创建链表
            u->next=M->next;
            M->next=u;
            M=u;
        }
        else{                          //如果是奇数，插入链表L2
            u=new node;                //创建新结点
            u->data=p->data;           //采用尾插法，创建链表
            u->next=N->next;
            N->next=u;
            N=u;
        }
        p=p->next;                     //p后移一位
    }
    cout<<"偶数项L1为：";
	outPut(&L1);
	cout<<"\n奇数项L2为：";
    outPut(&L2);                        //打印链表L2
    killList(&L1);                  //销毁链表L1
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
			p3 = p3->next;  //新表的指针后移一个

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
        cout<<"错误"; 
    p = q->next;
    while(p!=NULL)
    {
        if((p->data)-(q->data)>0)
        {
            q=p;//相当于q+1 
            p=p->next;//相当于p+1 
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
 
