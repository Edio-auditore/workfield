//��ջ
#include<iostream>
using namespace std;
 
typedef struct IsNode{
	char data;
	IsNode *next;
}sNode;
 
typedef char elementType;
void mymenu(){
	cout << "+-------------------------------------------------------------------------------+" << endl;
	cout << "|            ���� 1��10������ת��Ϊx������                                      |" << endl;
	cout << "|            ���� 2�ж���ѧ���ʽ�ĸ������Ƿ�ƥ��                               |" << endl;
	cout << "|            ���� 3 ������п��ܵĳ�ջ����                                      |" << endl;
  	cout << "|            ���� 4 �˳�                                                        |" << endl;
	cout << "+-------------------------------------------------------------------------------+" << endl;
	cout << "������Ҫѡ��Ĺ������:";
}

void initialStack(sNode *&top){
	top = NULL;
}

bool popStack(sNode *&top,elementType &x){
	if (top != NULL){
		sNode *u;
		u = top;
		x = top->data;
		top = top->next;
		delete u;
		return 0;
	}
	else{
		return 1;
	}
}

void pushStack(sNode *&top,elementType x){
	sNode *s;
	s = new sNode;
	s->data=x;
	s->next=top;
	top=s;
}

void popAll(sNode *& top){
	elementType x;
	if(top == NULL){
		cout << "ջ�գ�" << endl; 
		return ;
	}
	else{
		while(!popStack(top, x)){
			cout << x ;
		}
		cout <<endl;
		return ;
	}
}
 
sNode* numTrans(int num, int x)//num Ϊ10���Ƶ����֣�x��Ŀ��Ľ�����
{  
    sNode *top;
    top = NULL; 
	while(num != 0)
    {
    	int node = num % x;
        if(node >= 10)
        {
        
			pushStack(top, node - 10 + 'A');
        }
        else
        {
        
			pushStack(top, node + '0');
        }
        num /= x;
    }
    return top;
}

bool bracketMatch2Linked(string str) {
	sNode * u, *top;//����һ��ջ
	top = NULL;
	int len = str.length();//�����ѧ���ʽ�ĳ���
	bool tag = true;
	bool result;
	int i = 0;
	char x;
	while (i < len && tag == true) {
		switch (str[i]) {
		//������������ջ
		case '(':
		case '[':
		case '{':
			pushStack(top,str[i]);
			break;
		case ')':
			//ɨ�赽������ʱ�������ǰջ�գ������Ŷ���������
			if (top == NULL) {
				tag = false;
				result = false;
				break;
			}
			//�õ�ջ��Ԫ�أ�����ջ
			x = top->data;
			u = top;
			top = top->next;
			delete u;
			if(x == '(') {
				break;
			}else {
				tag = false;
				result = false;
				break;
			}
		case ']':
			if (top == NULL) {
				tag = false;
				result = false;
				break;
			}
			//�õ�ջ��Ԫ�أ�����ջ
			x = top->data;
			u = top;
			top = top->next;
			delete u;
			if (x == '[') {
				break;
			}
			else {
				tag = false;
				result = false;
				break;
			}
		case '}':
			if (top == NULL) {
				tag = false;
				result = false;
				break;
			}
			//�õ�ջ��Ԫ�أ�����ջ
			x = top->data;
			u = top;
			top = top->next;
			delete u;
			if (x == '{') {
				break;
			}
			else {
				tag = false;
				result = false;
				break;
			}
		default:
			break;
		}
		i++;
	}
	if (top == NULL && tag == true) {
		result = true;
	}else {
		result = false;
	}
	return result;
}
 
void legalSequenceLinked(sNode *top, int In[], int Out[], int len, int i, int j) { 
 
	sNode *u, *s;
	char x; 
	if(top == NULL && j >= len)  //�ٵݹ���ڣ������һ����ջ���� 
    { 
		for(int i = 0; i < len; i++){//��ӡ���� 
		    cout << Out[i];
		}
		cout << " ";
 	}else if(top != NULL && i<len)  //��ջ���գ���ջ�����л������� ��Ϊ���Ĳ��֡�
 	{ 
      //��ʱ��ջ 
  	popStack(top, x);
	Out[j] = x; 
  	j++; 
 	legalSequenceLinked(top, In, Out, len, i, j);   
  	j--;  //�ݹ鷵�أ��ָ�����ջǰ��״̬ 
    s = new sNode;  
	s->next = top;
	s->data = x;
    top = s; 
  	
      //��ʱ��ջ ��һ���������ǷǶԳƵġ�
    s = new sNode;
	s->data = In[i];
    s->next = top;
    top = s;
 	i++; 
 	legalSequenceLinked(top, In, Out, len, i, j); 
 	i--;     //�ָ�����ջǰ��״̬ 
	popStack(top, x);
	}else if(top != NULL && i>=len)  //��ջ���գ���ջ���������Ѿ�������� 
	{ 
     //��ʱ��ջ 
  		popStack(top, x);
		Out[j]=x; 
  		j++; 
  		legalSequenceLinked(top, In, Out, len, i, j); 
  		j--;   //�ָ�����ջǰ״̬ 
      	s = new sNode;
    	s->data = x;
    	s->next = top;
   		top = s;  
 	}else if(top == NULL && i<len)  //��ջ�գ���ջ����δ������� 
 	{ 
     //��ʱ��ջ
	    s = new sNode;
		s->data = In[i];
  	    s->next = top;
  		top = s;
  		i++; 
  		legalSequenceLinked(top, In, Out, len, i, j); 
  		i--;   //�ָ�����ջǰ��״̬ 
		popStack(top, x);
 	}	 
} 
