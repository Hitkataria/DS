#include<iostream>
using namespace std;

#define s 5
int queue[s];
int front=-1,rear=-1;   

int full()
{
    if ((rear+1)%s==front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty()
{
    if (front == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void enqueue(int x)
{
    if(full())
    {
        cout<<"Queue is full"<<endl;
        return ;
    }
    else 
    {
        if(front==-1)
        {
            front=0;           
        } 
        rear=(rear+1)%s;
        queue[rear]=x;
    }
}

int dequeue()
{
    int x;
    if (empty())
    {
        cout<<"Queue is empty"<<endl;
        return 0;
    }
    else
    {
        x=queue[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%s;
        }
        return x;
    }
}

void display()
{
    int i;
    if(empty())
    {
        cout<<"Queue is empty:"<<endl;
        return ;
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%s)
        {
            cout<<queue[i]<<" ";
        }
        cout<<queue[rear]<<endl;
    }
}

int main()
{
    int n,x;
    while(1)
    {
        cout<<"1.Enqueue 2.Dequeue 3.Display 4.Exit"<<endl;
        cout<<"Enter your choice";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"Enter the element to be inserted"<<endl;
                cin>>x;
                enqueue(x);
                break;
            case 2:
                x=dequeue();
                if(x!=0)
                {
                    cout<<"The deleted element is "<<x<<endl;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}
