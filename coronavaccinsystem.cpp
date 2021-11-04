#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

class patient
{
private:
    int id;
    int pass;
    int day, mon, year;
    time_t now;
    char name[50];
    int age;
    int admin_usr_id = 232;
    int admin_pass = 232;
    int rd,rm,ry;

public:
    void registration();
    void showdata();
    int ptid();
    int ptpass();
    int regd();
    int regm();
    int regy();
    int random_num();
    int admid();
    int admpass();
};

int main();
int display_all(int , int);

int patient::random_num()
{
	srand(time(0));
	int random = rand();

	cout << "ID number = " << random << endl;
    return random;
}

int patient::ptid()
{
    return id;
}

int patient::ptpass()
{
    return pass;
}

int patient::admid()
{
    return admin_usr_id;
}

int patient::admpass()
{
    return admin_pass;
}

int patient::regd()
{
    int day,mon,year;

    time_t now;

    tm* now_Local;

    now = time(0);

    now_Local = localtime(&now);

    day = now_Local->tm_mday;
    mon = now_Local->tm_mon+1;
    year = now_Local->tm_year+1900;

    return day;

}

int patient::regm()
{
    int day,mon,year;

    time_t now;

    tm* now_Local;

    now = time(0);

    now_Local = localtime(&now);

    day = now_Local->tm_mday;
    mon = now_Local->tm_mon+1;
    year = now_Local->tm_year+1900;

    return mon;

}

int patient::regy()
{
    int day,mon,year;

    time_t now;

    tm* now_Local;

    now = time(0);

    now_Local = localtime(&now);

    day = now_Local->tm_mday;
    mon = now_Local->tm_mon+1;
    year = now_Local->tm_year+1900;

    return year;

}


void patient::registration()
{
    id = random_num();
    cout<<"Enter An New Patient Password: ";
    cin>>pass;
    cout <<"Enter patient name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout <<"Enter patient age: ";
    cin>> age;
    rd = regd();
    rm = regm();
    ry = regy();
}

void patient::showdata()
{
    cout <<"Patient ID"<<id<<endl;
    cout <<"Patient Pass"<<pass<<endl;
    cout <<"Patient Name: "<<name<<endl;
    cout <<"Age: "<<age<<endl;
    cout <<"Registration Date: "<<rd<<endl;
    cout <<"Registration Date: "<<rd<<" /"<<rm<<" /"<<ry<<endl;
    cout <<"First Dose Date: "<<rd<<" /"<<rm+1<<" /"<<ry<<endl;
    cout <<"Second Dose Date: "<<rd<<" /"<<rm+2<<" /"<<ry<<endl;
}

void New_Entry()
{
    char ch;
    patient pt;
    ofstream outfile;
    outfile.open("patient.txt",ios::binary|ios::app);
    pt.registration();
    outfile.write((char *) (&pt), sizeof(patient));
    outfile.close();
    cout<<"\nPatient record has been created!!!"<<endl;
    cin.ignore();

    cout<<"Enter another new patient? (y/n): ";
    cin>>ch;
    switch(ch)
    {
        case 'y': New_Entry();
        break;
        case 'n': main();
        break;
        default: cout<<"\a"; main();
    }

}

void Search(int n, int p)
{

    char ch;
    int idnum;
    int passnum;
    patient pt;
    ifstream infile;
    infile.open("patient.txt",ios::binary);
    if(!infile)
    {
        cout<<"Error!! File could not be opend!!!"<<endl;
        cin.ignore();
        cin.get();
    }

    bool flag= false;
    while(infile.read((char *) (&pt), sizeof(patient)))
    {
        if(pt.ptid()== n && pt.ptpass()== p)
        {
            pt.showdata();
            flag = true;
        }
    }
    infile.close();
    if(flag = false)
    {
        cout<<"File not exist!!!"<<endl;
        cin.ignore();
        cin.get();
    }

    cout<<"Search another? (y/n): ";
    cin>>ch;
    switch(ch)
    {
        case 'y': cout<<"Enter Patient ID: "; cin>>idnum;
        cout<<"Enter Patient Password: "; cin>>passnum;
        Search(idnum,passnum); break;

        case 'n': main();
        break;

        default: cout<<"\a"; main();
    }

}

int display_all(int n, int p)
{

	patient pt;
	if(pt.admid() == n && pt.admpass() == p)
    {
	ifstream infile;
	infile.open("patient.txt",ios::binary);
	if(!infile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";


        while(infile.read((char *) (&pt), sizeof(patient)))
        {
            pt.showdata();
            cout<<"\n\n====================================\n";
        }

	infile.close();
	cin.ignore();
	}
}

void Delete(int n, int p)
{
    char ch;
    int idnum;
    int passnum;
    patient pt;
    ifstream infile;
    infile.open("patient.txt",ios::binary);
    if(!infile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}

	ofstream outfile;
	outfile.open("Temp.txt",ios::out);
	while(infile.read((char *) (&pt), sizeof(patient)))
    {
        if(pt.ptid() !=  n && pt.ptpass() != p)
        {
            outfile.write((char *) (&pt) , sizeof(patient));
        }
    }
    outfile.close();
    infile.close();
    remove("patient.txt");
    rename("Temp.txt","patient.txt");
    cin.ignore();
    cout<<"Patient Data is been deleted!!!"<<endl;

    cout<<"Delete another? (y/n): ";
    cin>>ch;
    switch(ch)
    {
        case 'y': cout<<"Enter Patient ID: "; cin>>idnum;
        cout<<"Enter Patient Password: "; cin>>passnum;
        Delete(idnum,passnum); break;

        case 'n': main();
        break;
        default: cout<<"\a"; main();
    }
}

int main()
{
    int ch;
    int idnum;
    int passnum;

    system("cls");
    cout<<"Main manu"<<endl<<endl;
    cout<<"1.Registration"<<endl<<endl;
    cout<<"2.Search Patient"<<endl<<endl;
    cout<<"3.Delete"<<endl<<endl;
    cout<<"4.Admin Login"<<endl<<endl;
    cout<<"5.Exit"<<endl<<endl;
    cout<<"Select your option: ";
    cin>>ch;
    system("cls");

    switch(ch)
    {
        case 1: New_Entry(); break;

        case 2: cout<<"Enter Patient ID: "; cin>>idnum;
        cout<<"Enter Patient Password: "; cin>>passnum;
        Search(idnum,passnum); break;

        case 3: cout<<"Enter Patient ID: "; cin>>idnum;
        cout<<"Enter Patient Password: "; cin>>passnum;
        Delete(idnum,passnum); break;

        case 4: cout<<"Enter Admin ID: "; cin>>idnum;
        cout<<"Enter Admin Password: "; cin>>passnum;
        display_all(idnum,passnum); break;

        case 5: break;

        default : cout<<"\a"; main();
    }

    return 0;
}
