#include<iostream>
#include<string.h>
using namespace std;
#define Max 1
class client
{
    public:

    char name[100];
    long long int telephone;

    client()
    {
        strcpy(name,"");
        
    }

    void print()
    {
        cout<<name<<"\t"<<telephone;
    }

    void scan()
    {
        cout<<"\nEnter name:";
        cin>>name;

        cout<<"\nEnter telephone:";
        cin>>telephone;
    }

    int operator !=(client x)
    {
        if(strcmp(name,x.name)==0 && telephone==x.telephone)
        {
            return 0;
        }
        return 1;
    }
};
class Hashtable
{
    client arr[Max];
    public:
    Hashtable()
    {
        for(int i=0;i<Max;i++)
        {
            arr[i].telephone=-1;
          
        }
    }

    void insert_LWTR(client x)
    {
        int pos=x.telephone%Max;
        if(arr[pos].telephone==-1)
        {
            arr[pos]=x;
            return;
        }
        else
        {
            int c=0;
            while(arr[pos].telephone!=-1)
            {
                pos=(pos+1)%Max;
                c++;
                if(c==Max)
                {
                    cout<<"\nTable full";
                    return;
                }
            }
            arr[pos]=x;
        }

    }

    void show_LWTR()
    {
        cout<<"\nHash table witout repalcement:\n";
        for(int i=0;i<Max;i++)
        {
            cout<<i<<"\t";
            arr[i].print();
            cout<<endl<<"---------------------"<<endl;
        }
    }

    void insert_LWR(client x)
    {
        int pos=x.telephone%10;
        if(arr[pos].telephone==-1)
        {
            arr[pos]=x;
            return;
        }
        else
        {
            client syn=arr[pos];
            client temp;
            if(syn.telephone%Max==x.telephone%Max)
            {
                temp=x;
            }
            else
            {
                temp=syn;
                arr[pos]=x;
            }
            int c=0;
            while(arr[pos].telephone!=-1)
            {
                pos=(pos+1)%Max;
                c++;
                if(c==Max)
                {
                    cout<<"\nTable full";
                     arr[pos]=temp;
                    return;
                }
            }

            arr[pos]=temp;
        }
    }

    void show_LWR()
    {
         cout<<"\nHash table with repalcement:\n";
        for(int i=0;i<Max;i++)
        {
            cout<<i<<"\t";
            arr[i].print();
            cout<<endl<<"------------------------"<<endl;
        }
    }

    int count_LWR(client x)
    {
        int pos=x.telephone%Max;
        int c=0;
        while(arr[pos].telephone!=-1 && arr[pos]!=x)
        {
            c++;
            pos=(pos+1)%Max;
              if(c==Max)
            {
                return 0;
            }
        }
        if(arr[pos].telephone==-1)
        {
            return 0;
        }
        return c;   
    }

    int count_LWTR(client x)
    {
        int pos=x.telephone%Max;
        int c=0;
        while(arr[pos].telephone!=-1 && arr[pos]!=x)
        {
            c++;
            pos=(pos+1)%Max;
            if(c==Max)
            {
                return 0;
            }
        }
        if(arr[pos].telephone==-1)
        {
            return 0;
        }
        return c;
    }

   
};

int main()
{
    Hashtable hWR;
    Hashtable hWTR;
    // while(1)
    // {
    //     cout<<"\nEnter telephone no:(-1 to stop):";
    //     int telephone_no;
    //     cin>>telephone_no;

    //     if(telephone_no==-1)
    //     {
    //         break;
    //     }
    //     h.insert_LWTR(telephone_no);

    // }

    // h.show_LWTR();

    client c;
    char ch;
     while(1)
    {
        cout<<"\nDO you want add the client:(y\\n):";
        cin>>ch;
        if(ch=='n')
        {
            break;
        }
        cout<<"\nEnter client to telephone book:";
        c.scan();
        
       
        hWR.insert_LWR(c);
        hWTR.insert_LWTR(c);
    }

    hWR.show_LWR();
    cout<<endl<<endl;
    hWTR.show_LWTR();

    client x;
    cout<<"\nEnter telephone no to search:";
    x.scan();
    cout<<hWR.count_LWR(x)<<"    "<<hWTR.count_LWTR(x)<<endl;
    return 0;
}