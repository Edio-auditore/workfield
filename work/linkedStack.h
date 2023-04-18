//链栈
#include<iostream>
using namespace std;
 
typedef struct IsNode{
	char data;
	IsNode *next;
}sNode;
 
typedef char elementType;
void mymenu(){
	cout << "+-------------------------------------------------------------------------------+" << endl;
	cout << "|            输入 1将10进制数转换为x进制数                                      |" << endl;
	cout << "|            输入 2判断数学表达式的各括号是否匹配                               |" << endl;
	cout << "|            输入 3 求出所有可能的出栈序列                                      |" << endl;
  	cout << "|            输入 4 退出                                                        |" << endl;
	cout << "+-------------------------------------------------------------------------------+" << endl;
	cout << "输入你要选择的功能序号:";
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
		cout << "栈空！" << endl; 
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
 
sNode* numTrans(int num, int x)//num 为10进制的数字，x是目标的进制数
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
	sNode * u, *top;//定义一个栈
	top = NULL;
	int len = str.length();//获得数学表达式的长度
	bool tag = true;
	bool result;
	int i = 0;
	char x;
	while (i < len && tag == true) {
		switch (str[i]) {
		//所有左括号入栈
		case '(':
		case '[':
		case '{':
			pushStack(top,str[i]);
			break;
		case ')':
			//扫描到右括号时，如果当前栈空，右括号多于左括号
			if (top == NULL) {
				tag = false;
				result = false;
				break;
			}
			//得到栈顶元素，并出栈
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
			//得到栈顶元素，并出栈
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
			//得到栈顶元素，并出栈
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
	if(top == NULL && j >= len)  //①递归出口，获得了一个出栈序列 
    { 
		for(int i = 0; i < len; i++){//打印序列 
		    cout << Out[i];
		}
		cout << " ";
 	}else if(top != NULL && i<len)  //②栈不空，入栈序列中还有数据 此为核心部分。
 	{ 
      //此时出栈 
  	popStack(top, x);
	Out[j] = x; 
  	j++; 
 	legalSequenceLinked(top, In, Out, len, i, j);   
  	j--;  //递归返回，恢复到出栈前的状态 
    s = new sNode;  
	s->next = top;
	s->data = x;
    top = s; 
  	
      //此时入栈 这一步和其他是非对称的。
    s = new sNode;
	s->data = In[i];
    s->next = top;
    top = s;
 	i++; 
 	legalSequenceLinked(top, In, Out, len, i, j); 
 	i--;     //恢复到入栈前的状态 
	popStack(top, x);
	}else if(top != NULL && i>=len)  //③栈不空，入栈序列数据已经处理结束 
	{ 
     //此时出栈 
  		popStack(top, x);
		Out[j]=x; 
  		j++; 
  		legalSequenceLinked(top, In, Out, len, i, j); 
  		j--;   //恢复到出栈前状态 
      	s = new sNode;
    	s->data = x;
    	s->next = top;
   		top = s;  
 	}else if(top == NULL && i<len)  //④栈空，入栈序列未处理结束 
 	{ 
     //此时入栈
	    s = new sNode;
		s->data = In[i];
  	    s->next = top;
  		top = s;
  		i++; 
  		legalSequenceLinked(top, In, Out, len, i, j); 
  		i--;   //恢复到入栈前的状态 
		popStack(top, x);
 	}	 
} 
