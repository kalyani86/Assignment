#include<iostream>
using namespace std;
#define Max 10;
#include<stack>
#include<queue>

class Node
{
    int data;
    Node* next;
    public:
    Node(int d)
    {
        data=d;
        next=NULL;
    }
    friend class Graph;
};

class Graph
{
    Node** head;
    int vertices;
    string * landmark;
    int *visited;
    public:
    Graph()
    {
        cout<<"\nenter no of landmark:";
        cin>>vertices;
        visited=new int[vertices];
        head=new Node*[vertices];
        landmark=new string[vertices];

        for(int i=0;i<vertices;i++)
        {
            visited[i]=0;
            cout<<"\nenter name of landmark at "<<i<<" :";
            cin>>landmark[i];
            head[i]=NULL;
        }
    }

    void create();
    void insert(int i,int j);
    void display();
    void DFS(int);
    void compelete_DFS();
    void BFS(int);
    void DFS_non_rec(int);
    void clear();

    string getlandmark(int);
};
void Graph::clear()
{
    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
    }
}
string Graph::getlandmark(int i)
{
    if(i<0 || i>=vertices)
    {
        cout<<"\nNot a valid landmark";
        return "";
    }
    return landmark[i];
}

void Graph::create()
{
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            int y;
            cout<<"\nIf there exit a edge bet "<<getlandmark(i)<<" and "<<getlandmark(j)<<" Enter 1 else 0:";
            cin>>y;
            if(y==1)
            {
                insert(i,j);
            }
           
        }
    }
}
 void Graph::insert(int i,int j)
 {
    if(head[i]==NULL)
    {
        Node* p=new Node(j);
        head[i]=p;
        return;
    }
    Node* p=head[i];
    while(p->next!=0)
    {
        p=p->next;
    }
    p->next=new Node(j);
 }

 void Graph::display()
 {
    for(int i=0;i<vertices;i++)
    {
        Node* p=head[i];
        cout<<getlandmark(i)<<" - > ";
        while(p!=0)
        {
            cout<<getlandmark(p->data)<<" - > ";
            p=p->next; 
        }
        cout<<endl;
    }
 }

void Graph::compelete_DFS()
{
    int c=0;
    for(int i=0;i<vertices;i++)
    {
        if(visited[i]==0)
        {
            DFS(i);
            c++;
        }
    }
    if(c==0)
    {
        cout<<"\nThere is no cycle";
    }
    else{
        cout<<"\nThere is cycle";
    }
}

void Graph::DFS(int i)
{
    if(i<0 || i>=vertices)
    {
        cout<<"\nEnter vertx is invlid";
        return;
    }
    cout<<getlandmark(i)<<" ";
    Node* p=head[i];
    visited[i]=1;

    while(p!=0)
    {
        if(!visited[p->data])
        {
            DFS(p->data);
        }
        p=p->next;
    }   
}

void Graph::DFS_non_rec(int i)
{
    if(i<0 || i>=vertices)
    {
        cout<<"\nEnter vertx is invlid";
        return;
    }
    stack<int>s;
    s.push(i);
    visited[i]=1;
    while (!s.empty())
    {
        i=s.top();
        s.pop();
        cout<<getlandmark(i)<<" ";
       
        Node* p=head[i];
        while(p!=0)
        {
            if(!visited[p->data]){
                 visited[p->data]=1;
                 s.push(p->data);
            }
            p=p->next;
        }
    }
    
}

void Graph::BFS(int i)
{
     if(i<0 || i>=vertices)
    {
        cout<<"\nEnter vertx is invlid";
        return;
    }
    queue<int>q;
    cout<<getlandmark(i)<<" ";
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        Node* p=head[i];
        while(p!=0)
        {
            if(!visited[p->data])
            {
                q.push(p->data);
                visited[p->data]=1;
                cout<<getlandmark(p->data)<<" ";
            }
            p=p->next;
        }
        
    }

}
int main()
{
    Graph g;
    g.create();
    g.display();

    int i;
    cout<<"\nEnter start:";
    cin>>i;

//     g.DFS(i);
//    g.compelete_DFS();

    //g.DFS_non_rec(i);
    g.BFS(i);
    return 0;
}