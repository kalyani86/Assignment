#include<iostream>
using namespace std;

class Node
{
    int data;
    int lbit;
    int rbit;
    Node* rlink;
    Node* llink;

    public:
    Node()
    {
        data=0;
        lbit=0;
        rbit=0;
        rlink=NULL;
        llink=NULL;
    }

    Node(int d)
    {
        data=d;
        lbit=0;
        rbit=0;
        rlink=NULL;
        llink=NULL;
    }
    friend class TBT;
};
class TBT
{
    Node* head;
    public:
    TBT()
    {
        head=new Node(0);
        head->rlink=head;
        head->rbit=1;
        head->llink=head;

    }

    void create();
    void insert(int x);
    void Linsert(Node* ,Node*);
    void Rinsert(Node*,Node*);
    void inorder();
    Node* inorder_succ(Node*);
    void preorder();
    Node* preorde_succ(Node*);
    void Deletion(Node*,Node*);
    void searchTodelete(int);
    ~TBT()
    {
        delete head;
    }
};

void TBT::Linsert(Node *parent, Node *child)
{
    child->lbit=parent->lbit;
    child->llink=parent->llink;
    child->rlink=parent;
    parent->lbit=1;
    parent->llink=child;

}

void TBT::Rinsert(Node *parent, Node *child)
{
    child->rbit=parent->rbit;
    child->rlink=parent->rlink;
    child->llink=parent;
    parent->rbit=1;
    parent->rlink=child;
   
}
void TBT::create()
    {
        while(1)
        {
            int x;
            cout<<"\nEnter data :(-1 to stop):";
            cin>>x;
            if(x==-1)
            {
                return ;
            }
            insert(x);
        }
    }

void TBT::insert(int x)
{
    Node* p=new Node(x);
    if(head->lbit==0)
    {
       Linsert(head,p);
        return ;
    }

    Node* t=head->llink;
    Node* parent=head->llink;
    while(1)
    {
        parent=t;
        if(t->data>x)
        {
            if(t->lbit==1){
            t=t->llink;}
            else{
                break;
            }
        }
        else if(t->data<x)
        {
            if(t->rbit==1){
            t=t->rlink;}
            else{
                break;
            }
        }
        else{
            cout<<"\nDuplicate";
            return;
        }
    }
    if(parent->data<x)
    {
        Rinsert(parent,p);
    }
    else if(parent->data>x)
    {
        Linsert(parent,p);
    }
    else{
        cout<<"\nDupliacate";
        
    }

}
Node* TBT::inorder_succ(Node* t)
{
    if(t->rbit==0)
    {
        return t->rlink;
    }
    t=t->rlink;
    while(t->lbit==1)
    {
        t=t->llink;
    }

    
    return t;
}

void TBT::inorder()
{
    Node* t=head->llink;
    if(head==t)
    {
        cout<<"\nEmpty";
        return;
    }
    while(t->lbit==1)
    {
        t=t->llink;
    }

    while(t!=head)
    {
        cout<<t->data<<" ";
        t=inorder_succ(t);
    }
}


Node* TBT::preorde_succ(Node* t)
{
    if(t->lbit==1)
    {
        return t->llink;
    }
    while (t->rbit==0)
    {
       t=t->rlink;
    }
    return t->rlink;

    
}

void TBT::preorder()
{
    Node* t=head->llink;
    if(t==head)
    {
        cout<<"\empty";
        return;
    }
    while(t!=head)
    {
        cout<<t->data<<" ";
        t=preorde_succ(t);
    }
}

void TBT::searchTodelete(int x)
{
    Node* t=head->llink;
    if(t==head)
    {
        return;
    }

    Node* parent=t;
    Node* child=t;
    while(1)
    {
      
        if(child->data<x)
        {
             parent=child;
            if(child->rbit==1)
            {
                child=child->rlink;
            }
            else{
                break;
            }
        }
        else if(child->data>x)
        {
             parent=child;
            if(child->lbit==1)
            {
                child=child->llink;
            }
            else{
                break;
            }
        }
        else 
        {
            Deletion(parent,child);
            break;
        }
          
    }
}
void TBT::Deletion(Node* parent,Node* child)
{
    Node* t=head->llink;
    if(t==head)
    {
        return;
    }
    Node* p=NULL;
   while(1)
   {
        if(child->lbit==1 && child->rbit==1)
        {
           
           p=child;
           parent=child;
           child=child->rlink;
           while(child->lbit==1)
           {
                parent=child;
                child=child->llink;
           }
           p->data=child->data;
        }
        if(child->lbit==1 && child->rbit==0)
        {
            p=child;
            parent=child;
            child=child->llink;
            p->data=child->data;
        }
        if(child->lbit==0 && child->rbit==1)
        {
            p=child;
            parent=child;
            child=child->rlink;
            p->data=child->data;
        }
        if(child->lbit==0 && child->rbit==0)
        {
            p=child;
            cout<<"\nparent->data"<<parent->data<<"\tchild->data:"<<child->data;
            if(parent->llink==child)
            {
                parent->lbit=child->lbit;
                parent->llink=child->llink;
            }
            else{
                parent->rbit=child->rbit;
                parent->rlink=child->rlink;
            }
            delete p;
            return;
        }
   }
}
int main()
{
    TBT t;
    t.create();
    cout<<"\nInorder:";
    t.inorder();
    // cout<<"\npreorder:";
    // t.preorder();


    int x;
    cout<<"\nEnter element to deltete:";
    cin>>x;

    t.searchTodelete(x);

    cout<<"\nInorder:";
    t.inorder();
    return 0;
}