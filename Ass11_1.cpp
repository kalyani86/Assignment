#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class stdRecord;
class student
{
    
    int roll_no;
    char name[100];
    char div;
    char add[100];
    public:
    student()
    {
        roll_no=0;
        strcpy(name,"");
        div=' ';
        strcpy(add,"");
    }
    student(int r,char* n,char d,char* a)
    {
        roll_no=r;
        strcpy(name,n);
        div=d;
        strcpy(add,a);
    }

    friend ostream& operator <<(ostream& out,student s)
    {
        cout<<"\nname:"<<s.name;
        cout<<"\nroll no:"<<s.roll_no;
        cout<<"\ndiv:"<<s.div;
        cout<<"\nadd:"<<s.add;
        return cout;
    }

    friend istream& operator >>(istream& in,student& s)
    {
        in.ignore(1);
        cout<<"\nEnter name:";
        in.getline(s.name,100);

        cout<<"\nEnter roll no:";
        in>>s.roll_no;

        cout<<"\nEnter division:";
        in>>s.div;

        in.ignore(1);
        cout<<"\nEnter address:";
        in.getline(s.add,100);
        return in;
    }
    friend fstream& operator>>(fstream& obj,student &s)
    {
        obj>>s.name;
        obj>>s.roll_no;
        obj>>s.div;
        obj>>s.add;
        return obj;
    }

    friend fstream& operator <<(fstream& obj,student& s)
    {
        obj<<s.name<<" ";
        obj<<s.roll_no<<" ";
        obj<<s.div<<" ";
        obj<<s.add<<" ";
        return obj;
    }
  
    bool operator==(student s)
    {
        if(strcmp(name,s.name)==0 && roll_no==s.roll_no && strcmp(add,s.add)==0 && div==s.div)
        {
            return true;
        }
        return false;
    }
   friend class stdRecord;
    
};

class stdRecord
{
    char path[100];
    public:
    stdRecord()
    {
        strcpy(path,"D://dsl_programs//second_Sem//std.txt");
    }

    void addData(student s)
    {
        fstream fobj;
        fobj.open(path,ios::app);

        if(fobj.fail())
        {
            cout<<"\nfile not connected to add data";
            exit(0);
        }

        cout<<"\nfile connected to add data";
        fobj<<s;
        fobj<<endl;
        fobj.close();
    }

    void display()
    {
        fstream fobj;
        fobj.open(path,ios::in);
        if(fobj.fail())
        {
            cout<<"\nFail to connect to display";
            exit(0);
        }

        cout<<"\nconnected to read";

        student s;
        while(fobj>>s)
        {
            cout<<s;
            cout<<endl;
        }
        fobj.close();
    }

    void search(int roll)
    {
         fstream fobj;
        fobj.open(path,ios::in);
        if(fobj.fail())
        {
            cout<<"\nFail to connect to display";
            exit(0);
        }

        cout<<"\nconnected to search";

        student s;
        while(!fobj.eof())
        {
            fobj>>s;
            if(roll==s.roll_no)
            {
                cout<<"\nstudent found";
                cout<<s;
                return;
            }
        }
        cout<<"\nstudent not found";
        fobj.close();

    }

    void deleteStudent(int roll)
    {
        fstream fobj;
        fobj.open(path,ios::in);
        if(fobj.fail())
        {
            cout<<"\nFail to connect to display";
            exit(0);
        }

        cout<<"\nconnected to delete";

        fstream newobj;
        newobj.open("D://dsl_programs//second_Sem//temp.txt",ios::app);
        student std;
        int f=0;
        while( fobj>>std)
        {
            if(std.roll_no!=roll){
                newobj<<std;
                newobj<<endl;
                cout<<endl;
            }
            else{
                f=1;
            }
        }
        fobj.close();
        newobj.close();
        if(f==0)
        {
            cout<<"\nno student found to delete";
        } 
        remove("D://dsl_programs//second_Sem//std.txt");
        rename("D://dsl_programs//second_Sem//temp.txt","D://dsl_programs//second_Sem//std.txt");
       


    }
};

int main()
{
    while(1)
    {
        cout<<"\n----- MENU -----";
        cout<<"\n1-add\n2-display\n3-search\n4-delete\n5-exit";
        int choise;
        cout<<"\nEnter choise:";
        cin>>choise;
        student s;
        stdRecord rec;
        int roll;
        switch (choise)
        {
            case 1:cin>>s;
                    rec.addData(s);
                    break;
            case 2:rec.display();
                    break;
            case 3:cout<<"\nEnter roll no to search:";
                    cin>>roll;
                    rec.search(roll);
                    break;
            case 4:cout<<"\nEnter roll no delete:";
                    cin>>roll;
                    rec.deleteStudent(roll);
                    break;
            case 5:cout<<"\n--- Exit ----";
                    exit(0);
        default:cout<<"\n";
                exit(0);
            break;
        }
    }
   
}