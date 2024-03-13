#include<iostream>

using namespace std;

class Node
{
    string str;
    Node* next;

    public:
    Node()
    {
        str="";
        next=NULL;
    }

    Node(string s)
    {
        str=s;
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

    void insert(char key,string str)
    {
        int pos=int(key-'a');
        Node* p=new Node(str);

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
                cout<<p->str<<"-->";
                p=p->next;
            }
            cout<<endl;
            i++;
        }
    }

    void find(char key,string s)
    {   
        
    }   
};
int main()
{
    Dictonary d;
   while(1)
   {
        char key;
        string str;

        cout<<"\nenter key value:";
        cin>>key;
        cout<<"\nenter string :";
        cin>>str;
        if(str=="stop")
        {
            break;
        }
        d.insert(key,str);
   }
   d.display();
    
    return 0;
}