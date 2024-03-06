#include<iostream>
using namespace std;
#define Max 10

class Hashtable
{
    long long int LWR[Max];
    long long int LWTR[Max];

    public:
    Hashtable()
    {
        for(int i=0;i<Max;i++)
        {
            LWR[i]=-1;
            LWTR[i]=-1;
        }
    }

    void insert_LWTR(long long int x)
    {
        int pos=x%10;
        if(LWTR[pos]==-1)
        {
            LWTR[pos]=x;
            return;
        }
        else
        {
            while(LWTR[pos]!=-1)
            {
                pos=(pos+1)%Max;
            }
            LWTR[pos]=x;
        }

    }

    void show_LWTR()
    {
        cout<<"\nHash table witout repalcement:\n";
        for(int i=0;i<Max;i++)
        {
            cout<<i<<" | "<<LWTR[i];
            cout<<endl<<"-----"<<endl;
        }
    }

    void insert_LWR(long long int x)
    {
        int pos=x%10;
        if(LWR[pos]==-1)
        {
            LWR[pos]=x;
            return;
        }
        else
        {
            int syn=LWR[pos];
            int temp;
            if(syn%Max==x%Max)
            {
                temp=x;
            }
            else
            {
                temp=syn;
                LWR[pos]=x;
            }

            while(LWR[pos]!=-1)
            {
                pos=(pos+1)%Max;
            }

            LWR[pos]=temp;
        }
    }

    void show_LWR()
    {
         cout<<"\nHash table with repalcement:\n";
        for(int i=0;i<Max;i++)
        {
            cout<<i<<" | "<<LWR[i];
            cout<<endl<<"-----"<<endl;
        }
    }

    int count_LWR(long long int x)
    {
        int pos=x%10;
        int c=0;
        while(LWR[pos]!=-1 && LWR[pos]!=x)
        {
            c++;
            pos=(pos+1)%Max;
        }
        if(LWR[pos]==-1)
        {
            return 0;
        }
        return c;   
    }

    int count_LWTR(long long int x)
    {
        int pos=x%10;
        int c=0;
        while(LWTR[pos]!=-1 && LWTR[pos]!=x)
        {
            c++;
            pos=(pos+1)%Max;
        }
        if(LWTR[pos]==-1)
        {
            return 0;
        }
        return c;
    }

   
};

int main()
{
    Hashtable h;
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


     while(1)
    {
        cout<<"\nEnter telephone no:(-1 to stop):";
        int telephone_no;
        cin>>telephone_no;

        if(telephone_no==-1)
        {
            break;
        }
        h.insert_LWR(telephone_no);
        h.insert_LWTR(telephone_no);
    }

    h.show_LWR();
    cout<<endl<<endl;
    h.show_LWTR();

    int x;
    cout<<"\nEnter telephone no to search:";
    cin>>x;
    cout<<h.count_LWR(x)<<"    "<<h.count_LWTR(x)<<endl;
    return 0;
}