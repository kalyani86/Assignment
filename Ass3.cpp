#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *llink;
    Node *rlink;
    int rbit;
    int lbit;

    Node()
    {
        data = 0;
        llink = NULL;
        rlink = NULL;
        rbit = 0;
        lbit = 0;
    }

    Node(int d)
    {
        data = d;
        llink = NULL;
        rlink = NULL;
        rbit = 0;
        lbit = 0;
    }
};

class TBT
{
    Node *head;

public:
    TBT()
    {
        head = NULL;
    }

    Node *gethead()
    {
        return head;
    }

    void create();
    void Linsert(Node *parent, Node *child);
    void Rinsert(Node *parent, Node *child);
    Node *insuc(Node *p);
    void inorder();
    void insert(int x);
    void preorder();
    void deleteNode(Node*,Node*);
    void searchTodelete(int x);
};

void TBT::searchTodelete(int x)
{
   
    if(head==NULL || head->llink==NULL)
    {
        cout<<"\nnot found";
        return;
    }
    Node* T=head->llink;
    Node*  parent=T;
    Node* child=T;
    while(1)
    {
        parent=child;
        if(T->data>x)
        {
            if(T->lbit==1)
            {
                T=T->llink;            
            }
            else{
                cout<<"\nnot found";
                return;
            }
        }
        else if(T->data<x)
        {
            if(T->rbit==1)
            {
                T=T->llink;
            }
            else{
                cout<<"\nnot found";
                return;
            }
        }
        else{
            child=T;
            return;
        }
        
    }

    cout<<parent->data;
}

void TBT::deleteNode(Node* parent,Node* child) 
{

}
Node *TBT::insuc(Node *temp)
{
    if (temp->rbit == 0)
    {
        return temp->rlink;
    }
    else
    {
        temp = temp->rlink;
        while (temp->lbit != 0)
        {
            temp = temp->llink;
        }
        return temp;
    }
}

void TBT::inorder()
{
    if (head == nullptr)
    {
        cout << "\nTree is empty!!!";
        return;
    }
    if(head->llink==head)
    {
        cout<<"\nempty";
        return;
    }
    Node *temp = head->llink;
    while (temp->lbit != 0)
    {
        temp = temp->llink;
    }
    while (1)
    {
        cout << " " << temp->data << " ";
        temp = insuc(temp);
        if (temp == head)
            return;
    }
}
void TBT::Linsert(Node *parent, Node *child)
{
    parent->llink = child;
    parent->lbit = 1;
    child->llink = parent->llink;
    child->lbit = parent->lbit;
    child->rlink = parent;
    child->rbit = 0;
}

void TBT::Rinsert(Node *parent, Node *child)
{
    parent->rlink = child;
    parent->rbit = 1;
    child->rlink = parent->rlink;
    child->rbit = parent->rbit;
    child->llink = parent;
    child->lbit = 0;
}
void TBT::create()
{
   
    int x;
    while (1)
    {
        cout << "\nEnter data(0-stop):";
        cin >> x;
        if (x == 0)
        {
            break;
        }
        insert(x);
    }
}

// void TBT::insert(int x)
// {
//     Node *T = head->llink;
//     Node *newnode = new Node(x);
//     if (T == head)
//     {
//         head->llink = newnode;
//         newnode->rlink = head;
//         newnode->llink = head;
//         head->lbit = 1;
//         return;
//     }
//     Node *parent, *child;
//     parent = T;
//     child = T;

//     while (1)
//     {
//         cout << 1;
//         parent = child;
//         if (child->data < x)
//         {
//             if (child->rbit == 1 || child->rlink == head)
//             {
//                 break;
//             }
//             child = child->rlink;
//         }
//         else if (child->data > x || child->llink == head)
//         {
//             if (child->lbit == 1)
//             {
//                 break;
//             }
//             child = child->llink;
//         }
//         else
//         {
//             cout << "\nDuplicate";
//             delete newnode;
//             return;
//         }
//     }

//     if (parent->data < x)
//     {
//         newnode->llink = parent;
//         newnode->rlink = parent->rlink;
//         newnode->rbit = parent->rbit;
//         parent->rbit = 1;
//         parent->rlink = newnode;
//         if (child != head) {
//             newnode->rbit = 1;
//         }
//     }
//     else if (parent->data > x)
//     {
//         newnode->lbit = parent->lbit;
//         newnode->llink = parent->llink;
//         newnode->rlink = parent;
//         parent->lbit = 1;
//         parent->llink = newnode;
//          if (child != head) {
//             newnode->lbit = 1;
//         }
//     }
//     else
//     {
//         cout << "\nduplicate;";
//     }
// }



void TBT::insert(int x)
{
    Node *p=new Node(x);
    if(head==NULL)
    {
        head=new Node();
        head->rbit=1;
        head->rlink=head;
        head->lbit=1;
        head->llink=head;
        head->llink=p;
        p->llink=head;
        p->rlink=head;
    }
    else
    {
        Node *link=head->llink;
        while(link->data!=x)
        {
            if(x < link->data)
            {
                if(link->lbit==0)
                {
                    p->llink=link->llink;
                    p->rlink=link;
                    link->lbit=1;
                    link->llink=p;
                    break;
                }
                link=link->llink;
            }
            else
            {
                if(link->rbit==0)
                {
                    p->rlink=link->rlink;
                    p->llink=link;
                    link->rbit=1;
                    link->rlink=p;
                    break;
                }
                link=link->rlink;
            }
            if(link->data==x)
            {
                cout<<"\nDuplicate Data"<<endl;
            }
        }
    }
}

void TBT::preorder()
{
    Node* T=head->llink;
    int flag=1;

    while(T!=head)
    {
       while(flag!=0)
       {
            cout<<T->data<<" ";
            if(T->lbit==1)
            {
                T=T->llink;
            }
            else{
                break;
            }
       }
       flag=T->rbit;
       T=T->rlink;
    }
}
int main()
{
    TBT t;
    t.create();
    cout << "\ninorder:";
    t.inorder();
    cout<<endl;
    //t.preorder();
    cout<<"serach:";
    t.searchTodelete(9);
    return 0;
}