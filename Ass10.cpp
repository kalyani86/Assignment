#include<iostream>
using namespace std;

class student
{
    string name;
    int marks;
    public:
    student()
    {
        name="";
        marks=0;
    }

    student(string s,int m)
    {
        name=s;
        marks=m;
    }
    void getstudent()
    {
        cout<<"\nEnter name:";
        cin>>name;

        cout<<"\nEnter marks:";
        cin>>marks;
    }


    void show()
    {
        cout<<"\nname:"<<name<<"  marks:"<<marks<<endl;
    }
    friend class heap;
};


class heap
{
    student * Sheap;
    int n;
    public:
    heap()
    {
        cout<<"\nEnter number of student:";
        cin>>n;

        Sheap=new student[n];
        for(int i=0;i<n;i++)
        {
            Sheap[i].getstudent();
        }
    }


    void display()
    {
        for(int i=0;i<n;i++)
        {
            Sheap[i].show();
        }
    }

    void downadjust(int i,int m)
    {
        int j;
        while((2*i+1)<m)
        {
            j=2*i+1;
            if((j+1)<m && (Sheap[j].marks<Sheap[j+1].marks))
            {
                j=j+1;
            }
            if(Sheap[i].marks<Sheap[j].marks)
            {
                swap(Sheap[i],Sheap[j]);
                i=j;
            }
            else{
                break;
            }
        }
    }

    void heapSort()
    {
        for(int ind=(n/2-1);ind>=0;ind--)
        {
            downadjust(ind,n);
        }
       
        int ind=n-1;
        int m=n-1;
        while (ind>1)
        {
            ind=m;
            swap(Sheap[0],Sheap[ind]);
            m--;
            downadjust(0,m+1);

        }
        
    }
};
int main()
{
    heap h;
    h.display();
    cout<<endl<<endl;
    h.heapSort();
    h.display();
    return 0;
}