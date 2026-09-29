#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *first=NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=x;
    temp->next=NULL;
    return temp;
}

void insert_first(int x)
{
    struct node *t,*p;
    t=create_node(x);

    if(first==NULL)
    {
        first=t;
        t->next=first;
    }
    else
    {
        p=first;

        while(p->next!=first)
            p=p->next;

        t->next=first;
        p->next=t;
        first=t;
    }
}

void insert_last(int x)
{
    struct node *t,*p;
    t=create_node(x);

    if(first==NULL)
    {
        first=t;
        t->next=first;
    }
    else
    {
        p=first;

        while(p->next!=first)
            p=p->next;

        p->next=t;
        t->next=first;
    }
}

void insert_after(int x,int value)
{
    struct node *t,*p;
    t=create_node(x);

    if(first==NULL)
    {
        cout<<"List is empty"<<endl;
        free(t);
    }
    else
    {
        p=first;

        do
        {
            if(p->info==value)
            {
                t->next=p->next;
                p->next=t;
                return;
            }

            p=p->next;

        }while(p!=first);

        cout<<"Node not found"<<endl;
        free(t);
    }
}

void delete_first()
{
    struct node *t,*p;

    if(first==NULL)
        cout<<"List is empty"<<endl;
    else if(first->next==first)
    {
        t=first;
        cout<<"Deleted element: "<<t->info<<endl;
        first=NULL;
        free(t);
    }
    else
    {
        p=first;

        while(p->next!=first)
            p=p->next;

        t=first;
        cout<<"Deleted element: "<<t->info<<endl;

        first=first->next;
        p->next=first;

        free(t);
    }
}

void delete_last()
{
    struct node *t,*p;

    if(first==NULL)
        cout<<"List is empty"<<endl;
    else if(first->next==first)
    {
        t=first;
        cout<<"Deleted element: "<<t->info<<endl;
        first=NULL;
        free(t);
    }
    else
    {
        p=first;

        while(p->next->next!=first)
            p=p->next;

        t=p->next;

        cout<<"Deleted element: "<<t->info<<endl;

        p->next=first;
        free(t);
    }
}

void delete_after(int value)
{
    struct node *t,*p;

    if(first==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        p=first;

        do
        {
            if(p->info==value)
            {
                t=p->next;

                if(t==first)
                    cout<<"Cannot delete first node using this operation"<<endl;
                else
                {
                    cout<<"Deleted element: "<<t->info<<endl;
                    p->next=t->next;
                    free(t);
                }

                return;
            }

            p=p->next;

        }while(p!=first);

        cout<<"Node not found"<<endl;
    }
}

void display()
{
    struct node *t;

    if(first==NULL)
        cout<<"List is empty"<<endl;
    else
    {
        t=first;

        do
        {
            cout<<t->info<<" ";
            t=t->next;

        }while(t!=first);

        cout<<endl;
    }
}

int main()
{
    int ch,x,value;

    while(1)
    {
        cout<<"\n1.Insert at beginning";
        cout<<"\n2.Insert at end";
        cout<<"\n3.Insert after a given node";
        cout<<"\n4.Delete first node";
        cout<<"\n5.Delete last node";
        cout<<"\n6.Delete node after a given node";
        cout<<"\n7.Display";
        cout<<"\n8.Exit";

        cout<<"\nEnter your choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter the element to be inserted:"<<endl;
                cin>>x;
                insert_first(x);
                break;

            case 2:
                cout<<"Enter the element to be inserted:"<<endl;
                cin>>x;
                insert_last(x);
                break;

            case 3:
                cout<<"Enter the element and node value:"<<endl;
                cin>>x>>value;
                insert_after(x,value);
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                cout<<"Enter the node value after which node is to be deleted:"<<endl;
                cin>>value;
                delete_after(value);
                break;

            case 7:
                display();
                break;

            case 8:
                cout<<"Program is ended"<<endl;
                return 0;
        }
    }

    return 0;
}