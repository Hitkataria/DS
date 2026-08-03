#include<iostream>

using namespace std;

#define s 20
int tos=-1;
char stk[s];

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

void push(char x)
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

char pop()
{
	char x;
	if(!empty())
	{
		x=stk[tos];
		tos--;
		return x;
	}
	else
		{
    	cout << "Stack is Empty" << endl;
    	return '\0'; 
		}
}

char peek()
{
	if(!empty())
	return stk[tos];
	else 
	return '\0';
}

int priority(char op) 
{ 
	if(op == '+' || op == '-') 
		return 1; 
	else if(op == '*' || op == '/') 
		return 2; 
	else if(op == '^') 
		return 3; 
	else 
		return 0;
 }

 int main() 
 { 
	char infix[50], postfix[50];
	int i = 0, j = 0; 
	cout << "Enter your infix expression: "; 
	cin >> infix; 
	while(infix[i] != '\0') 
	{ 
		if((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
		 { 
			postfix[j] = infix[i]; j++; 
		}
		 else if(infix[i] == '(') { push(infix[i]); } else if(infix[i] == ')') 
		 { 
			while(peek() != '(') { postfix[j] = pop(); j++; 
			} 
			pop(); 
		}
		 else
		 	{
			 while(!empty() && priority(peek()) >= priority(infix[i])) 
			 {
			  postfix[j] = pop(); j++; 
			} 
			push(infix[i]); 
		}
		 i++; 
		} 
		while(!empty()) 
		{ 
		 postfix[j] = pop(); j++; 
		} 
		postfix[j] = '\0'; 
		cout << "Postfix Expression: " << postfix << endl; 
	}
