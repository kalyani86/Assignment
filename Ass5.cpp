#include<iostream>

using namespace std;

class Node
{
    string str;
    string mean;
    Node* next;

    public:
    Node()
    {
        str="";
        mean="";
        next=NULL;
    }

    Node(string s,string mn)
    {
        str=s;
        mean=mn;
        next=NULL;
    }
    friend class Dictonary;
};

class Dictonary
{
    Node* dict[26];
    public:
    Dictonary()
    {
        for(int i=0;i<26;i++)
        {
            dict[i]=NULL;
        }
    }

    void insert(string str,string mean)
    {
        int pos=int(str[0]-'a');
        Node* p=new Node(str,mean);

        if(dict[pos]==NULL)
        {
            dict[pos]=p;
            return ;
        }

        Node* q=dict[pos];
        while(q->next!=0)
        {
            q=q->next;
        }
        q->next=p;
    }


    void display()
    {
        int i=0;
        while(i<26)
        {
            Node* p=dict[i];
            cout<<char(i+'a')<<"-->";
            while(p!=0)
            {
                cout<<" | "<<p->str<<" - "<<p->mean<<" | "<<"-->";
                p=p->next;
            }
            cout<<endl;
            i++;
        }
    }

    void find(string s)
    {   
        int pos=int(s[0]='a');
        if(dict[pos]==NULL)
        {
            return;
        }

        Node* p=dict[pos];
        while(p!=0)
        {
            if(p->str==s)
            {
                cout<<"\nfound";
                return;
            }
            p=p->next;
        }
    }
    
       
};
int main()
{
    Dictonary d;
   while(1)
   {

        string str;
        string mean;
      
        cout<<"\nenter string :";
        cin>>str;
        if(str=="stop")
        {
            break;
        }cout<<"\nenter meaning:";
        cin>>mean;

        d.insert(str,mean);
   }
   d.display();
    
    return 0;
}