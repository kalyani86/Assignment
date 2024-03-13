#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

class HashNode
{
    string word;
    string mean;
    HashNode *next;
    public:
        HashNode()
        {
            word="";
            mean="";
            next=NULL;
        }
        HashNode(string wd,string mn)
        {
            word=wd;
            mean=mn;
            next=NULL;
        }
        friend class HashTable;
};

class HashTable
{
    HashNode *arr[26];
    public:
        HashTable()
        {
            for(int i=0;i<26;i++)
            {
                arr[i]=NULL;
            }
        }
        int hashFunc(string word)
        {
            return (int (toupper(word[0]))-int('A'));
        }
        
        void insertInDic(string wrd,string mn)
        {
            HashNode *p;
            HashNode *newNode = new HashNode(wrd,mn);
            int ind=hashFunc(wrd);
            if(arr[ind]==NULL)
            {
                arr[ind]=newNode;
            }
            else{
                HashNode *temp=arr[ind];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }
        }

        void searchInDic(string wrd)
        {
            int ind=hashFunc(wrd);
            HashNode *temp=arr[ind];
            while(temp!=NULL && temp->word != wrd)

            {
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"\n"<<wrd<<" not present in dictionary"<<endl;
                return;
            }
            cout<<"\nMeaning of word "<<wrd<<" is "<<temp->mean<<endl;
        }

        void deleteInDic(string wrd)
        {
            int ind = hashFunc(wrd);
            HashNode *p=arr[ind];
            HashNode *temp=NULL;
            while(p->word!=wrd && p!=NULL)
            {
                temp=p;
                p=p->next;
            }
            if(p==NULL)
            {
                cout<<wrd<<" not present in dictionary. Can't delete"<<endl;
                return;
            }
            if(p->next==NULL)
            {
                arr[ind]=NULL;
                delete p;
                return;
            }
            temp->next=p->next;
            delete p;
            
        }

        void display()
        {
            for(int i=0;i<26;i++)
            {
                cout<<char('A'+i)<<" : ";
                if(arr[i]!=NULL)
                {
                    HashNode *temp=arr[i];
                    while(temp!=NULL)
                    {
                        cout<<temp->word<<" | "<<temp->mean<<"  ->  ";
                        temp=temp->next;
                    }
                    cout<<" --- | --- ";
                    cout<<endl;
                }
                else
                {
                    cout<<" --- | --- "<<endl;
                }
            }
        }
};

int main()
{
    HashTable ht;
    int op;
    char ch;
    string wrd;
    string mn;
    do
    {
        cout<<"\n****OPTIONS***\n\n1.Insert\n2.Search\n3.Delete\n4.Display"<<endl;
        cout<<"\nEnter operation no to perform: ";
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"\n\n---INSERT---"<<endl;
                cout<<"\nEnter wrd: ";
                cin.ignore(1);
                getline(cin,wrd);
                cout<<"\nEnter it's meaning: ";
                getline(cin,mn);
                ht.insertInDic(wrd,mn);
                break;
            case 2:
                cout << "\n\n---SEARCH---" << endl;
                cout<<"\nEnter wrd to search: ";
                cin.ignore(1);
                getline(cin,wrd);
                ht.searchInDic(wrd);
                break;
            case 3:
                cout << "\n\n---DELETE---" << endl;
                cout<<"\nEnter wrd to delete: ";
                cin.ignore(1);
                getline(cin,wrd);
                ht.deleteInDic(wrd);
                break;
            case 4:
                cout << "\n\n---DISPLAY---" << endl;
                ht.display();
                break;
            default:
                cout<<"\nEnter valid choice"<<endl;
                break;
        }
        cout<<"\n\nWant to continue?(y/n) ";
        cin>>ch;
    }while(ch=='y');

    cout<<"\n\n**** THANK YOU! ****"<<endl;

    return 0;
}