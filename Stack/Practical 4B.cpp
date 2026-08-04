#include<iostream>

using namespace std;

#define s 20
int tos=-1;
int stk[s];

int empty()
{
	if(tos==-1)
	return 1;
	else
	return 0;
}

int full()
{
	if(tos==s-1)
	{
	return 1;
}
else{
	return 0;
}
}

void push(int x)
{
	if(!full())
	{
		++tos;
		stk[tos]=x;
	}
	else{
		cout<<"Stack Overflow"<<endl;
	}
}

int pop()
{
	int x;
	if(!empty())
	{
		x=stk[tos];
		tos--;
		return x;
	}
	else
		{
    	cout << "Stack is Empty" << endl;
    	return -1;
		}
}

int cal(char op,int op1,int op2)
	{
		int r;
		switch(op)
		{
			case '+':
				r=op1+op2;
				break;
			
			case '-':
				r=op1-op2;
				break;
			
			case '*':
				r=op1*op2;
				break;
				
			case '/':
				r=op1/op2;
				break;	
				
			default:
				cout<<"invalid operator"<<endl;
				return 0;
		}
		return r;
}

int main()
{

	char post[50];
	int p1,p2,r;
	int i=0;
	
	cout<<"Emter your expretions: ";
	cin>>post;
	
	while(post[i]!='\0')
	{
		if(post[i]>='0' && post[i]<='9')
		{
			push(post[i]-'0');
		}
		else
		{
			p2=pop();
			p1=pop();
			r=cal(post[i],p1,p2);
			push(r);
		}
		i++;
	}
	cout<<"result:"<<pop()<<endl;
}

