#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *left,*right;
};

struct node *root=NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=x;
    temp->left=temp->right=NULL;
    return temp;
}

void setleft(int x,struct node *p)
{
    struct node *temp;
    temp=create_node(x);
    p->left=temp;
}

void setright(int x,struct node *p)
{
    struct node *temp;
    temp=create_node(x);
    p->right=temp;
}

void inorder(struct node *p)
{
    if(p==NULL)
        return;
    else
    {
        inorder(p->left);
        cout<<p->info<<" ";
        inorder(p->right);
    }
}

void preorder(struct node *p)
{
    if(p==NULL)
        return;
    else
    {
        cout<<p->info<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p)
{
    if(p==NULL)
        return;
    else
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->info<<" ";
    }
}

int main()
{
   int n;
   char ch;
   struct node *p,*q;

   cout<<"Enter the root node: ";
   cin>>n;
   root=create_node(n);
   
   while(1)
   {
    cout<<"Do you want to continue (y/n): ";
    cin>>ch;
    if(ch=='n' || ch=='N')
        break;

    cout<<"Enter the node: ";
    cin>>n;
        p=root;
        q=NULL;
        while(p!=NULL)
        {
            q=p;
            if(n<p->info)
            p=p->left;
            else    
            p=p->right;
        }
        if(n<q->info)
        setleft(n,q);
        else
        setright(n,q);
   }
   cout<<"\nInorder Traversal of the tree is: ";
   inorder(root);
   cout<<endl;

   cout<<"Menu based code to call tree traversals"<<endl;
   while(1)
   {
    cout<<"1.Inorder"<<endl;
    cout<<"2.Preorder"<<endl;
    cout<<"3.Postorder"<<endl;
    cout<<"4.Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>n;

    switch(n)
    {
        case 1:
            inorder(root);
            cout<<endl;
            break;

        case 2:
            preorder(root);
            cout<<endl;
            break;

        case 3:
            postorder(root);
            cout<<endl;
            break;

        case 4:
            exit(0);
    }
   }
}