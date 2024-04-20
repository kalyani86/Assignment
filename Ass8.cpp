#include<iostream>
using namespace std;
#define MAX 10
#define infinity 999999
class Node
{
    string key;
    Node* left;
    Node* right;
    public:
    Node()
    {
        left=NULL;
        right=NULL;
    }

    Node(string d)
    {
        key=d;
        left=NULL;
        right=NULL;
    }
    friend class OBST;
};

class OBST
{
    Node* root;
    public:
    OBST()
    {
        root=NULL;
    }
    void create(string [],float[],float[],int);
    Node* construct(string key[],float r[MAX][MAX],int i,int j);
    void display(Node*);
    Node* getroot();
    int find(float c[MAX][MAX],int,int );

};
Node* OBST::getroot()
{
    return root;
}
void OBST::create(string key[],float p[],float q[],int n)
{
    float w[MAX][MAX],c[MAX][MAX],r[MAX][MAX];
    for(int i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=0;
        r[i][i]=0;
    }

    
    for(int step=1;step<=n;step++)
    {
        
        for(int i=0;i<=n-step;i++)
        {
            int j=i+step;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            int k=find(c,i,j);
            cout<<i<<" "<<j<<" "<<k<<" "<<endl;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }


    root=construct(key,r,0,n);
}

int OBST::find(float c[MAX][MAX],int i,int j)
{
    int min=infinity;
   
    int ind;
    for(int k=i+1;k<=j;k++)
    {
        if((c[i][k-1]+c[k][j])<min)
        {
            min=c[i][k-1]+c[k][j];
            ind=k;
        }
    }
    return ind;
}

Node* OBST::construct(string key[],float r[MAX][MAX],int i,int j)
{
    if(i==j)
    {
        return NULL;
    }
    int k=r[i][j];
    Node* p=new Node(key[k-1]);
    p->left=construct(key,r,i,k-1);
    p->right=construct(key,r,k,j);
    return p;

}

void OBST::display(Node* r)
{
    if(r==NULL)
    {
        return ;
    }

    display(r->left);
    cout<<r->key<<" ";
    display(r->right);
}
int main()
{
    float p[MAX],q[MAX];
    string key[MAX];
    int n;
    cout<<"\nEnter no of keys:";
    cin>>n;


    for(int i=0;i<n;i++)
    {
        cout<<"\nenter keys:";
        cin>>key[i];
    }

    for(int i=1;i<=n;i++)
    {
        cout<<"\nEnter p"<<i<<" :";
        cin>>p[i];
    }

    for(int i=0;i<=n;i++)
    {
        cout<<"\nEnter q"<<i<<" :";
        cin>>q[i];
    }

    OBST o;
    o.create(key,p,q,n);
    o.display(o.getroot());
    return 0;
}