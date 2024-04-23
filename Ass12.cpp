#include<iostream>
#include<fstream>
using namespace std;

class student
{
    int roll;
    string name;
    char div;
    string add;
    public:
    student()
    {
        roll=0;
        name="";
        div=' ';
        add="";
    }
    student(int r,string n,char d,string a)
    {
        roll=r;
        name=n;
        div=d;
        add=a;
    }
    friend fstream &operator<<(fstream &out1,student &s);
    friend fstream &operator>>(fstream &in1,student &s);
    friend ostream &operator<<(ostream &out1,student &s);
    void display(fstream &in,student &s);
    void search(fstream &in,int x,student &s);
    void delete1(fstream &in,int x,student &s,int n);
   
};

fstream &operator<<(fstream &out1,student &s)
{
    out1<<s.roll<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    out1<<endl;
    return out1;
}

fstream &operator>>(fstream &in1,student &s)
{
    in1>>s.roll;
    in1>>s.name;
    in1>>s.div;
    in1>>s.add;
    return in1;
}

ostream &operator<<(ostream &out1,student &s)
{
    out1<<s.roll<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    cout<<endl;
    return out1;
}
void student::display(fstream &in,student &s)
{
    in.open("anu.txt",ios::in);
    while(1)
    {
        in>>s;
        if(in.eof())
        {
            break;
        }
        cout<<s;
    }
    in.close();
   
}

void  student::search(fstream &in,int x,student &s)
{
    in.open("anu.txt",ios::in);
    while(1)
    {
        in>>s;
        if(s.roll==x)
        {
            cout<<s;
            break;
        }
        if(in.eof())
        {
            cout<<"Element not found"<<endl;
        }
    }
    in.close();
}

void student::delete1(fstream &in,int x,student &s,int n)
{
    student arr[n];
    hash1 h1;
    in.open("anus.txt",ios::in);
    for(int i=0;i<n;i++)
    {
        in>>s;
        arr[i]=s;
    }
    in.close();
    in.open("anu.txt",ios::out | ios::trunc );
    for(int i=0;i<n;i++)
    {
        if(arr[i].roll==x)
        {
            continue;
        }
        else
        {
            int l=in.tellp();
            in>>s;
            s=arr[i];
            h1.insert(s.roll,l);
            cout<<s;
        }
    }
    h1.display_hash();
    in.close();

}





int main()
{

    hash1 h;
    student s;
    fstream myfile;
    int c=1;
    int n;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            myfile.open("anu.txt",ios::out);
            cout<<"Enter number of entries:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int roll_no;
                string name;
                char div;
                string add;
                cout<<"Enter roll_no:";
                cin>>roll_no;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                cout<<"Enter address:";
                cin>>add;
                student s1(roll_no,name,div,add);
                int loc=myfile.tellp();
                myfile<<s1;
                h.insert(roll_no,loc);
               
            }
            myfile.close();
        }
        else if(c==2)
        {
            h.display_hash();
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter roll number to be searched:";
            cin>>x;
            int l=h.search_hash(x);
            cout<<l<<endl;
            myfile.open("anu.txt",ios::in);
            myfile.seekg(l,ios::beg);
            myfile>>s;
            cout<<s;
            myfile.close();
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter roll number to be searched:";
            cin>>x;
            h.delete_hash(x);
            s.delete1(myfile,x,s,n);
        }
    }
    return 0;
}