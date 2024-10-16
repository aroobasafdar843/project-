#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class Student
{
 int admno;
 char name[20];
 char gender;
 int std;
 float marks;
 float percentage;
 
 public:
  void getData();
  void showData();
  int getAdmno(){return admno;}
}s;

void Student::getData()
{
 cout<<"\n\nEnter Student Details......\n";
 cout<<"Enter Admission No.     : "; cin>>admno;
 cout<<"Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
 cout<<"Enter Gender (M/F)      : "; cin>>gender;
 cout<<"Enter Standard          : "; cin>>std;
 cout<<"Enter Marks (out of 500): "; cin>>marks;
 cout<<endl;
 percentage=marks*100.0/500.00;
}

void Student::showData()
{
 cout<<"\n\n.......Student Details......\n";
 cout<<"Admission No.     : "<<admno<<endl;
 cout<<"Full Name         : "<<name<<endl;
 cout<<"Gender            : "<<gender<<endl;
 cout<<"Standard          : "<<std<<endl;
 cout<<"Marks (out of 500): "<<marks<<endl;
 cout<<"Percentage        : "<<percentage<<endl;
 cout<<endl;
}

void addData()
{
 ofstream fout;
 fout.open("Students.dat",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n\nData Successfully Saved to File....\n";
}

void displayData()
{
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void searchData()
{
 int n, flag=0;
 ifstream fin;
 fin.open("Students.dat",ios::in|ios::binary);
 cout<<"Enter Admission no you want to search : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"The Details of Admission No. "<<n<<" :\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 cout<<"\n\nData Reading from File Successfully Done....\n";
}

void deleteData()
{
 int n, flag=0;
 ifstream fin;
 ofstream fout;

 fin.open("Students.dat",ios::in|ios::binary);
 


 cout<<"Enter Admission Number you want to delete : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"The Following Admission No. "<<n<<" has been removed :\n";
   s.showData();
   fout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();

 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("Students.dat");

}


void modifyData()
{
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.dat",ios::in|ios::out|ios::binary);
 
 cout<<"Enter Admission Number you want to Modify : ";
 cin>>n;
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"The Following Admission No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
}

void project()
{
 int ch;
 do
 {
  system("cls");
  cout<<"\n\n\n\t\t\t\t**********************************************\n";
  cout<<"\t\t\t\t******** Arooba Safdar _ 19101002-113 ********* \n";
  cout<<"\t\t\t\t**********************************************\n\n";
  cout<<"\t\t\t...............STUDENT MANAGEMENT SYSTEM..............\n";
  cout<<"\t\t\t======================================================\n";
  cout<<"\t\t\t0. Exit from Program\n";
  cout<<"\t\t\t1. Write Data to File\n";
  cout<<"\t\t\t2. Read Data From File\n";
  cout<<"\t\t\t3. Search Data From File\n";
  cout<<"\t\t\t4. Delete Data From File\n";
  cout<<"\t\t\t5. Modify Data in File\n";
  cout<<"\n\t\t\tEnter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: modifyData(); break;
  }
  system("pause");
 }while(ch);
}

int main()
{
 project();
}

