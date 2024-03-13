
#include <iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* lchild;
    TreeNode* rchild;

    TreeNode()
    {
   	 lchild=NULL;
   	 rchild=NULL;
   	 data=0;
    }

    TreeNode(int d)
    {
   	 data=d;
   	 lchild=NULL;
   	 rchild=NULL;
    }
};

class Tree
{
    TreeNode* root;

public:
    Tree()
    {
   	 root=NULL;
    }

    TreeNode* getRoot()
    {
   	 return root;
    }
    void create();
    void insert(int);
    void Inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);

    void heightOfEach();

    int height(TreeNode*);
    void NRinorder();
    void NRpreorder();
    void NRpostorder();
    void show();

    int longest_path_Number_of_Nodes(TreeNode*);
    int minElement(TreeNode* p);
    int maxElement(TreeNode* p);

    void swapNodes(TreeNode* p);
    int search(TreeNode* p,int x);
};

int Tree::search(TreeNode* p,int x)
{
    if(p==NULL)
    {
        return 0;
    }

    if(p->data==x)
    {
        return 1;
    }

    int res;
    if(x<p->data)
    {
        res=search(p->lchild,x);
    }
    else{
        res=search(p->rchild,x);
    }

    return res;

}
void Tree::swapNodes(TreeNode* p)
{
    if(p==NULL)
    {
        return;
    }

    swapNodes(p->lchild);
    swapNodes(p->rchild);
    swap(p->lchild,p->rchild);

}
int Tree::maxElement(TreeNode * p)
{
    if(p==NULL)
    {
        return 0;
    }

    if(p->rchild==NULL)
    {
        return p->data;
    }

    return maxElement(p->rchild);
}

int Tree::minElement(TreeNode* p)
{
    if(p==NULL)
        {
            return 0;
        }

        if(p->lchild==NULL)
        {
            return p->data;
        }

        return minElement(p->lchild);
}

int Tree::longest_path_Number_of_Nodes(TreeNode* p)
    {
        if(p==0)
        {
            return 0;
        }

        int l;
        l=longest_path_Number_of_Nodes(p->lchild);
        l=l+1;

        int r;
        r=longest_path_Number_of_Nodes(p->rchild);
        r=r+1;
        
        if(l<r)
        {
            return r;
        }
        else{
            return l;
        }
}
int Tree::height(TreeNode* t)
{
    int x,y;
    if(t==NULL)
    {
   	 return 0;
    }
    x=height(t->lchild);
    y=height(t->rchild);
    if(x>y)
    {
   	 return x+1;
    }
    else
    {
   	 return y+1;
    }


}

void Tree::heightOfEach()
{
    TreeNode* p=root;
    queue<TreeNode*>q;
    while(p!=0)
    {
   	 cout<<"height of "<<p->data<<" is "<<height(p)<<endl;
   	 if(p->lchild!=0)
   	 {
   		 q.push(p->lchild);
   	 }
   	 if(p->rchild!=0)
   	 {
   		 q.push(p->rchild);
   	 }
   	 if(!q.empty())
   	 {
   		 p=q.front();
   		 q.pop();
   	 }
   	 else
   	 {
   		 p=NULL;
   	 }

    }
}
void Tree::create()
{
    int x;
    cout<<"\nEnter -1 to stop insertion:";

    while(1)
    {
   	 cout<<"\nEnter data:";
   	 cin>>x;
   	 if(x==-1)
   	 {
   		 return;
   	 }
   	 insert(x);
    }
}

void Tree::insert(int data)
{
    TreeNode* p=new TreeNode(data);
    TreeNode* parent=root;
    TreeNode* child;
    if(root==NULL)
    {
   	 root=p;
   	 return;
    }
    else
    {
   	 parent=root;
   	 child=root;
   	 while(child!=0)
   	 {
   		 parent=child;
   		 if(parent->data<data)
   		 {
   			 child=parent->rchild;
   		 }
   		 else if(parent->data>data)
   		 {
   			 child=parent->lchild;
   		 }
         else{
            cout<<"\nDuplicate";
            return ;
         }
   	 }

   	 if(parent->data<data)
   	 {
   		 parent->rchild=p;
   	 }
   	 else if(parent->data>data)
   	 {
   		 parent->lchild=p;
   	 }
   	 else
   	 {
   		 cout<<"\nDuplicate";
   	 }
    }

}

void Tree::Inorder(TreeNode* t)
{

    if(t==NULL)
    {
   	 return;
    }

    Inorder(t->lchild);
    cout<<"data:"<<t->data<<endl;
    Inorder(t->rchild);
}

void Tree::NRinorder()
{
    TreeNode* t=root;
    stack<TreeNode*>s;
    while(1)
    {
   	 while(t!=0)
   	 {
   		 s.push(t);
   		 t=t->lchild;
   	 }

   	 if(s.empty())
   	 {
   		 return;
   	 }

   	 t=s.top();
   	 s.pop();
   	 cout<<"\ndata:"<<t->data;
   	 t=t->rchild;
    }
}

void Tree::NRpreorder()
{
    stack<TreeNode*>s;
    TreeNode* t=root;
    while(1)
    {
   	 while(t!=0)
   	 {
   		 cout<<"\ndata:"<<t->data;
   		 if(t->rchild!=0)
   		 {
   			 s.push(t->rchild);
   		 }
   		 t=t->lchild;
   	 }
   	 if(s.empty())
   	 {
   		 return;
   	 }
   	 t=s.top();
   	 s.pop();
    }
}

void Tree::preorder(TreeNode* t)
{

    if(t==NULL)
    {
   	 return;
    }

    cout<<"data:"<<t->data<<endl;
    preorder(t->lchild);
    preorder(t->rchild);
}

void Tree::NRpostorder()
{
    TreeNode* t=root;

    TreeNode* flag=new TreeNode(-1);
    stack<TreeNode*>s;
    while(1)
    {
   	 while(t!=0)
   	 {
   		 s.push(t);
   		 if(t->rchild!=0)
   		 {
   			 s.push(t->rchild);
   			 s.push(flag);
   		 }
   		 t=t->lchild;
   	 }
   	 if(s.empty())
   	 {
   		 return;
   	 }

   	 t=s.top();
   	 s.pop();

   	 while(t!=flag && !(s.empty()))
   	 {
   		 cout<<"\ndata:"<<t->data;
   		 t=s.top();
   		 s.pop();
   	 }


   	 if(!s.empty())
   	 {
   		 t=s.top();
   		 s.pop();
   	 }

    }
}
void Tree::postorder(TreeNode* t)
{

    if(t==NULL)
    {
   	 return;
    }

    postorder(t->lchild);
    postorder(t->rchild);
    cout<<"data:"<<t->data<<endl;
}

void Tree::show()
{
    TreeNode* p=root;
    queue<TreeNode*>q;
    while(p!=0)
    {
   	 cout<<p->data<<" ";
   	 if(p->lchild!=0)
   	 {
   		 q.push(p->lchild);
   	 }
   	 if(p->rchild!=0)
   	 {
   		 q.push(p->rchild);
   	 }
   	 if(!q.empty())
   	 {
   		 p=q.front();
   		 q.pop();
   	 }
   	 else
   	 {
   		 p=NULL;
   	 }

    }
}
int main() {


    Tree t;
    int res;
   int x;
    int choise;
   while(1)
   {
    cout<<"\n---------------- MENU ---------------------\n";
    cout<<"\n1-create\n2-show inorder\n3-insert\n4-find no of nodes in longest path\n5-min\n6-max\n7swap\n8-search\n9-exit\n";
    cout<<"\n--------------------------------------------\n";

    cout<<"\nEnter your choise:";
    cin>>choise;

    switch(choise)
    {
        case 1:t.create();
            break;
        case 2:t.Inorder(t.getRoot());
            break;
        case 3:cout<<"\nEnter data to insert:";
                cin>>x;
                t.insert(x);
                break;
        case 4:cout<<"\nno of nodes in longest path:"<<t.longest_path_Number_of_Nodes(t.getRoot())-1;
                    break;
        case 5:cout<<"\nMinimum value:"<<t.minElement(t.getRoot());
            break;
        case 6:cout<<"\nMaximum element:"<<t.maxElement(t.getRoot());
            break;
        case 7:t.swapNodes(t.getRoot());
            break;
        case 8:cout<<"\nenter node to search:";
            cin>>x;
            res=t.search(t.getRoot(),x);
            if(res==1)
            {
                cout<<"\nElement found";
            }
            else{
                cout<<"\nElement not found";
            }
            break;
        case 9:cout<<"\n------ Exit ------";
                exit(0);
        default:exit(0);
    
            

    }

   }
    return 0;
}

