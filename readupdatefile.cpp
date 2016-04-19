#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;


struct updateRecType {
  int transCode;
  int key;
  char first[10];
  char last[20];
  char address[30];
  char startDate[12];
  char endDate[12];
};




main() {
  fstream infile;

  updateRecType person;


  infile.open("Updates.dat", ios::binary | ios::in);
  int count=0;
  int input;
  cout<<setw(2)<<"Trans Code"<<setw(5)<<"Key"<<setw(12)<<"First Name"<<setw(22)<<"Last Name"<<setw(32)<<"Address"
        <<setw(14)<<"Start Date"<<setw(14)<<"End Date"<<endl;

  while (!infile.eof())
   {
    infile.read (reinterpret_cast <char*>(&person), sizeof(person));
    if (!infile.eof())
     {
      cout<<person.transCode<<setw(15)<<person.key<<setw(12)<<person.first<<setw(22)
          <<person.last<<setw(32)<<person.address
          <<setw(14)<<person.startDate<<setw(14)<<person.endDate<<endl;
      count++;
     }
   }
  infile.close();

   //cin>> input;
  return 0;
}



