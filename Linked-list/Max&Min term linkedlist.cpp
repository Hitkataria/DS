#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;
struct node *create_node(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

int max()
{
    if(first == NULL)
    {
        cout << "List is empty" << endl;
        return 0; 
    }
   int m=first->info,count=0;
    struct node *temp;
    temp=first;
    while(temp!=NULL)
    {
        if(temp->info>m)
        {
            m=temp->info;
        }
        count++;
        temp=temp->next;
    }
    return m;
}

int min()
{
    if(first == NULL)
    {
        cout << "List is empty" << endl;
        return 0; 
    }
    int m=first->info,count=0;
    struct node *temp;
    temp=first;
    while(temp!=NULL)
    {
        if(temp->info<m)
        {
            m=temp->info;
        }
        count++;
        temp=temp->next;
    }
    return m;
}

void insert_first(int x)
{
    struct node *temp;
    temp = create_node(x);
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void insert_last(int x)
{
    struct node *t,*p;
    t=create_node(x);
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        p=first;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
        t->prev=p;
    }
}

void insert(int x,int pos)
{
    struct node *t,*p;
    t=create_node(x);
    if(first==NULL)
    {
        first=t;
    }
    else
    {
        p=first;
        for(int i=1;i<pos-1 && p!=NULL;i++)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            cout<<"Position out of bounds"<<endl;
            free(t);
            return;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next!=NULL)
            p->next->prev=t;
        p->next=t;
    }
}

void delete_first()
{
    struct node *temp;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    temp=first;
    first=first->next;
    if(first!=NULL)
        first->prev=NULL;
    free(temp);
}

void delete_last()
{
    struct node *temp;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    temp=first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->prev!=NULL)
        temp->prev->next=NULL;
    else
        first=NULL;
    free(temp);
}

void delete_pos(int pos)
{
    struct node *temp;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    temp=first;
    for(int i=1;i<pos && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cout<<"Position out of bounds"<<endl;
        return;
    }
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        first=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    free(temp);
}

void display()
{
    struct node *temp;
    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    temp=first;
    while(temp!=NULL)
    {
        cout<<"Elements Are:"<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    int ch,x,pos;
    while(1)
    {
        cout<<"1.Insert at first"<<endl;
        cout<<"2.Insert at last"<<endl;
        cout<<"3.Insert at position"<<endl;
        cout<<"4.Delete at first "<<endl;
        cout<<"5.Delete at last"<<endl;
        cout<<"6.Delete at position"<<endl;
        cout<<"7.Display"<<endl;
        cout<<"8.Max value in the list"<<endl;
        cout<<"9.Min value in the list"<<endl;
        cout<<"10.Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter value to insert: ";
                cin>>x;
                insert_first(x);
                break;

            case 2:
                cout<<"Enter value to insert: ";
                cin>>x;
                insert_last(x);
                break;

            case 3:
                cout<<"Enter value to insert: ";
                cin>>x;
                cout<<"Enter position: ";
                cin>>pos;
                insert(x,pos);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout<<"Enter position to delete: ";
                cin>>pos;
                delete_pos(pos);
                break;

            case 7:
                display();
                cout<<endl;
                break;

            case 8:
                 cout<<"Max value in the list: "<<max()<<endl;
                 break;


            case 9:
                cout<<"Min value in the list: "<<min()<<endl;
                break;

            case 10:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}