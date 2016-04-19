#include <iostream>
#include <cstdlib>
#include <iomanip> 
#include <fstream>
#include <string.h>
using namespace std; 


struct CustomerType {
  int key;
  char first[10];
  char last[20];
  char address[30];
  char startDate[12];
  char endDate[12];
};




main() {
  fstream infile;
 fstream out;  
  CustomerType person;
   
  
  infile.open("NewMaster1.dat", ios::binary | ios::in);
  out.open("mergereport.txt",ios::out);
  int count=0;
  int input;

     out<<setw(5)<<"Key"<<setw(12)<<"First Name"<<setw(22)<<"Last Name"<<setw(32)<<"Address"
        <<setw(14)<<"Start Date"<<setw(14)<<"End Date"<<endl;
    
  while (!infile.eof())
   {
    infile.read (reinterpret_cast <char*>(&person), sizeof(person));
    if (!infile.eof())
     {
      out<<setw(5)<<person.key<<setw(10)<<person.first<<setw(12)<<person.last<<setw(15)<<person.address
        <<setw(14)<<person.startDate<<setw(14)<<person.endDate<<endl;
      count++;
     }
   }
  infile.close();
   
   //cin>> input;
  return 0;
}
