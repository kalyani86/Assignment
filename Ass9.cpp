#include<iostream>
using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int ht;
    public:
    Node()
    {
        ht=0;
        keyword="";
        meaning="";
        left=NULL;
        right=NULL;
    }

    Node(string k,string m)
    {   
        ht=0;
        keyword=k;
        meaning=m;
        left=NULL;
        right=NULL;
    }
    friend class AVL;
};

class AVL
{
    Node* root;
    public:
    AVL()
    {
        root=NULL;
    }

    int height(Node*);
    int BF(Node*);
    Node* rotateright(Node*);
    Node* rotatelefft(Node*);
    Node* LL(Node*);
    Node* RR(Node*);
    Node* RL(Node*);
    Node* LR(Node*);
    Node* insert(Node* r,string k,string m);
    void inorder(Node*);
    Node* & getroot();
    Node* Delete(Node*,string k);
   
};

Node* AVL::Delete(Node* r,string k)
{
    if(r==NULL)
    {
        return NULL;
    }
    else if(k>r->keyword)
    {
        r->right=Delete(r->right,k);
        if(BF(r)==2)
        {
            if(BF(r->left)>=0)
            {
                r=LL(r);
            }
            else{
                r=LR(r);
            }
        }
    }
    else if(k<r->keyword)
    {
        r->left=Delete(r->left,k);
        if(BF(r)==-2)
        {
            if(BF(r->right)<=0)
            {
                r=RR(r);
            }
            else{
                r=RL(r);
            }
        }
    }
    else{
        if(r->right!=0)
        {
            Node* p=r->right;
           // Node* t=r;
            while(p->left!=0)
            {  // t=p;
                p=p->left;
            }
            r->keyword=p->keyword;
            r->right=Delete(r->right,p->keyword);
            if(BF(r)==2)
            {
                if(BF(r->left)>=0)
                {
                    r=LL(r);
                }
                else{
                    r=LR(r);
                }
            }
        }
        else{
            return r->left;
        }
        r->ht=height(r);
        return r;
    }
}
Node* & AVL::getroot()
{
    return root;
}
void AVL::inorder(Node* r)
{
    if(r==NULL)
    {
        return;
    }
    inorder(r->left);
    cout<<r->keyword<<" "<<BF(r)<<" -->";
    inorder(r->right);
}
Node* AVL::insert(Node* r,string k,string m)
{
    if(r==NULL)
    {
        r=new Node(k,m);
    }
    else if(k>r->keyword)
    {
        r->right=insert(r->right,k,m);
        if(BF(r)==-2)
        {
            if(k>r->right->keyword)
            {
                r=RR(r);
            }
            else{
                r=RL(r);
            }
        }
    }
    else{
        r->left=insert(r->left,k,m);
        if(BF(r)==2)
        {
            if(k<r->left->keyword)
            {
                r=LL(r);
            }
            else{
                r=LR(r);
            }
        }
    }
    r->ht=height(r);
    return r;
}
int AVL::height(Node* t)
{
    int lh,rh;
    if(t==NULL)
    {
        return 0;
    }
    if(t->left==0)
    {
        lh=0;
    }
    else{
        lh=1+t->left->ht;
    }

    if(t->right==0)
    {
        rh=0;
    }
    else{
        rh=1+t->right->ht;
    }
    if(lh<rh)
    {
        return rh;
    }
    return lh;
}

int AVL::BF(Node* t)
{
    int lh,rh;
    if(t==0)
    {
        return 0;
    }
    if(t->left==0)
    {
        lh=0;
    }
    else{
        lh=1+t->left->ht;
    }

    if(t->right==0)
    {
        rh=0;
    }
    else{
        rh=1+t->right->ht;
    }

    return (lh-rh);

}

Node* AVL::rotatelefft(Node* x)
{
    Node* y=x->right;
    x->right=y->left;
    y->left=x;
    y->ht=height(y);
    x->ht=height(x);
    return y;
}

Node* AVL::rotateright(Node* x)
{
    Node* y=x->left;
    x->left=y->right;
    y->right=x;
    x->ht=height(x);
    y->ht=height(y);
    return y;
}

Node* AVL::LL(Node* t)
{
    return rotateright(t);
}

Node* AVL::RR(Node* t)
{
    return rotatelefft(t);
}

Node* AVL::LR(Node* t)
{
    t->left=rotatelefft(t->left);
    t=rotateright(t);
    return t;
}

Node* AVL::RL(Node* t)
{
    t->right=rotateright(t->right);
    return rotatelefft(t);
}

int main()
{
    AVL a;
    int i=0;
    while(i<7)
    {
       string k,m;
       cout<<"\nenter key:";
       cin>>k;
       cout<<"\nEnter meaning:";
       cin>>m;

       a.getroot()=a.insert(a.getroot(),k,m);
       i++;
    }

    a.inorder(a.getroot());
    a.Delete(a.getroot(),"23");
    cout<<endl<<endl;
    a.inorder(a.getroot());
    return 0;
}