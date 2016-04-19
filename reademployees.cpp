#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
struct employees
{
  char title[5];
  char  fname[31];
  char lname[31];
  int streetnum;
  char address[41];
  char city[41];
  char state[3];
  char zipcode[6];
  char email[31];
  int age;
  int salary;
};



main()
{
  fstream infile;
   fstream out;
  employees person;
   
   out.open("results.txt",ios::out);
  infile.open("employeesrec.dat", ios::binary | ios::in);
  int count=0;
  int input;
    out<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
  out<<"----------------------------------------------------------------------------------------------------------------------------------"<<endl;
  while (!infile.eof())
   { 
    infile.read (reinterpret_cast <char*>(&person), sizeof(person));
    if (!infile.eof())
     {
      out << setw(7) << left << person.title<<setw(9)<<person.fname<<setw(12)<<person.lname<<setw(6)<<person.streetnum<<" "<<
			setw(14)<<person.address<<setw(18)<<person.city<<setw(8)<<person.state<<setw(8)<<person.zipcode<<setw(6)<<person.age<<setw(13)<<person.salary
			<<person.fname<<person.lname<<person.email<<endl; 
      count++;
     }
   }

  infile.close();
   out.close();
   //cin>> input;
  return 0;
}


