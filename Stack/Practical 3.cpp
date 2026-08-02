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

void peek()
{
	if(tos==-1)
	{
		cout<<"Stack is empty "<<endl;
	}
	else
	{
		cout<<"top element is: "<<stk[tos]<<endl;
	}
}

void display()
{
	if(tos==-1)
	{
		cout<<"Stack is empty!"<<endl;
	}
	else
	{
		cout<<"Stack elemetns are: ";
		for(int i=0;i<=tos;i++)
				{
					cout<<stk[i]<<" ";
				}
	}
}
int main()
{
	int n,num,x;
	while(1)
	{
		cout<<"\n----STACK MENU----"<<endl;
		cout<<"1.push"<<endl<<"2.pop"<<endl<<"3.peek"<<endl<<"4.Display"<<endl<<"5.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>n;
		
		switch(n)
		{
			case 1:
				cout<<"Enter the element:";
				cin>>num;
				push(num);
				break;
				
			case 2:
  				  x = pop();

   				 if(x != -1)
  				  {
      				  cout<<"Deleted element: "<<x<<endl;
  				  }

    break;
				
			case 3:
				peek();
				
				break;
				
			case 4:
				display();
				break;
				
			case 5:
					cout<<"you are sucessfully exiting form your code"<<endl;
					return 0;
	
				
		
		default:
			cout<<"invalid choice"<<endl;
		}
	}
	return 0;
}
