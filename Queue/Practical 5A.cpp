#include<iostream>
using namespace std;

#define s 20
int queue[s];
int front=-1,rear=-1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                            

int full()
{
    if(rear==s-1)
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
    if(front==-1 || front>rear)
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
        cout<<"Queue Is Full"<<endl;
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }

        queue[++rear]=x;
    }
}

int dequeue()
{
    int x;
    if(empty())
    {
        return -1;
    }
    else 
    {
        x=queue[front];
        front++;
    }
    return x;
}

void display()
{
    if(empty())
    {
        cout<<"Queue Is Empty"<<endl;
    }
    else
    {
        cout<<"Queue Elements Are: ";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
 int h,x;
 while(1){
 cout<<"Select Choice Between 1 To 4"<<endl;
 cout<<"1.Insert\n2.Delete\n3.Disaplay\n4.Exit"<<endl;
 cout<<"Enter your choice: ";
 cin>>h;

 
 switch(h)
 {
    case 1:
         int n;

    cout << "How Many Elements Do You Want To Insert: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i + 1 << ": ";
        cin >> x;

        enqueue(x);
    }

        break;

    case 2:
        x=dequeue();
        if(x != -1)
  				  {
      				  cout<<"Deleted element: "<<x<<endl;
  				  }
                  else 
                  {
                    cout<<"Queue Is Empty"<<endl;
                  }

    break;

    case 3:
    display();
    break;

    case 4:
    cout<<"Your Successfully Exited the code...";
    return 0;

    default:
    cout<<"Invalid Choice"<<endl;

 }
}
}