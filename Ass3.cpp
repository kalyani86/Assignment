#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    
    int data;
    Node* llink;
    Node* rlink;
    int rbit;
    int lbit;

    Node()
    {
        data=0;
        llink=NULL;
        rlink=NULL;
        rbit=0;
        lbit=0;
    }

    Node(int d)
    {
        data=d;
         llink=NULL;
        rlink=NULL;
        rbit=0;
        lbit=0;
    }
};


class TBT
{
    Node* head;
    public:
    TBT()
    {
        head=NULL;
    }

    Node* gethead()
    {
        return head;
    }

    void create();
    void Linsert(Node* parent,Node* child);
    void Rinsert(Node* parent,Node* child);
    Node* insuc(Node* p);
    void inorder(Node* T);
    void insert(int x);
};

void TBT::inorder(Node* T)
{
    
    while(1)
    {

        T=insuc(T);
        if(T==head)
        {
            return;
        }
         cout<<T->data<<" ";
    }

}
Node* TBT::insuc(Node* p)
{
    Node* s=p->rlink;
    if(p->rbit==1)
    {
        while(p->lbit==1)
        {
            p=p->llink;
        }
    }
    return p;
}
void TBT::Linsert(Node* parent,Node* child)
{
    parent->llink=child;
    parent->lbit=1;
    child->llink=parent->llink;
    child->lbit=parent->lbit;
    child->rlink=parent;
    child->rbit=0;
}

void TBT::Rinsert(Node* parent,Node* child)
{
    parent->rlink=child;
    parent->rbit=1;
    child->rlink=parent->rlink;
    child->rbit=parent->rbit;
    child->llink=parent;
    child->lbit=0;
}
void TBT::create()
{
    head=new Node();
    head->rbit=1;
    head->llink=head;
    head->rlink=head;

    int x;
    while(1)
    {
        cout<<"\nEnter data(0-stop):";
        cin>>x;
        if(x==0)
        {
            break;
        }
        insert(x);
    }
    
}

void TBT::insert(int x)
{
    Node* T=head->llink;
    Node* newnode=new Node(x);
    if(T==head)
    {
        head->llink=newnode;
        newnode->rlink=head;
        newnode->llink=head;
        head->lbit=1;
        return;
    }
    Node* parent,*child;
    parent=T;
    child=T;

    while(child!=head)
    {
        cout<<1;
        parent=child;
        if(child->data<x)
        {
            if(child->rbit==1)
            {
                break;
            }
            child=child->rlink;
        }
        else if(child->data>x)
        {
            if(child->lbit==1)
            {
                break;
            }
            child=child->llink;
        }
        else{
            cout<<"\nDuplicate";
            delete newnode;
            return;
        }
    }

    if(parent->data<x)
    {
        newnode->llink=parent;
        newnode->rlink=parent->rlink;
        newnode->rbit=parent->rbit;
        parent->rbit=1;
        parent->rlink=newnode;

    }
    else if(parent->data>x)
    {
        newnode->lbit=parent->lbit;
        newnode->llink=parent->llink;
        newnode->rlink=parent;
        parent->lbit=1;
        parent->llink=newnode;
    }
    else{
        cout<<"\nduplicate;";
    }
    
    
    
}
int main()
{
    TBT t;
    t.create();
    cout<<"\ninorder:";
    t.inorder(t.gethead());

    return 0;
}