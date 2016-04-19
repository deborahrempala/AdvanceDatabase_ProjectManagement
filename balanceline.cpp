
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


struct CustomerType {
  int key;
  char first[10];
  char last[20];
  char address[30];
  char startDate[12];
  char endDate[12];
};




main() {
  fstream OldMaster;
  fstream updates;
  fstream newMaster;
  updateRecType updateRec;
  CustomerType oldMasterRec;
  CustomerType newMasterRec;
 int DUMMY_KEY= 99999999;
  int smallestKey;
 
OldMaster.open("OldMaster.dat", ios::binary | ios::in);
updates.open("Updates.dat", ios::binary | ios::in);
newMaster.open("NewMaster.dat",ios::binary |  ios::out);
OldMaster.read(reinterpret_cast<char*>(&oldMasterRec),sizeof(oldMasterRec));


if (OldMaster.eof())
  oldMasterRec.key = DUMMY_KEY;

  OldMaster.read(reinterpret_cast<char*>(&oldMasterRec),sizeof(oldMasterRec));

updates.read(reinterpret_cast<char*>(&updateRec),sizeof(updateRec));
if (updates.eof())
  updateRec.key = DUMMY_KEY;

if (oldMasterRec.key <= updateRec.key)
  smallestKey = oldMasterRec.key;
else
  smallestKey = updateRec.key;

bool thereIsARecord = false; bool cancelFlag = false;

while (smallestKey != DUMMY_KEY)
{
  while (smallestKey == oldMasterRec.key)
  {
    if (thereIsARecord)
    cout<<"error"<<endl;

    else
    {
      newMasterRec = oldMasterRec;
      thereIsARecord = true;
    }
    OldMaster.read(reinterpret_cast<char*>(&oldMasterRec), sizeof(oldMasterRec));
    if (OldMaster.eof())
      oldMasterRec.key = DUMMY_KEY;
  }
  
  while (updateRec.key == smallestKey)
  {
    switch (updateRec.transCode)
    {
      case 1: // new subscription
              updateRec.key == newMasterRec.key;
               updateRec.first == newMasterRec.first;
		 updateRec.last == newMasterRec.last;
		 updateRec.address == newMasterRec.address;
		 updateRec.startDate == newMasterRec.startDate;
                  updateRec.endDate == newMasterRec.endDate;


		thereIsARecord = true;   
              break;

      case 2: // renewal
              if (thereIsARecord)
              {
                updateRec.endDate == newMasterRec.endDate;

              }
              else
              {
                // there.s an error - record doesn.t exist
              }
              break;

      case 3: // cancellation
              if (thereIsARecord)
              {
                // do whatever is required to cancel
                  newMasterRec.key == NULL;
               	  newMasterRec.first =="         ";
                  newMasterRec.last== "                   ";
                  newMasterRec.address== "                             ";
                  newMasterRec.startDate == "           ";
                    newMasterRec.endDate == "           ";
 
                cancelFlag = true;
              }
              else
              {
                // there.s an error - record doesn.t exist
              }
              break;



      case 4: // change of address
              if (thereIsARecord)
              {
                 updateRec.address == newMasterRec.address;

              }
              else
              {
                // there.s an error - record doesn.t exist
              }
              break;
    }
    updates.read(reinterpret_cast<char*>(&updateRec),
                 sizeof(updateRec));
    if (updates.eof())
      updateRec.key = DUMMY_KEY;
  }
  if (thereIsARecord && !cancelFlag)
  {
    newMaster.write(reinterpret_cast<char*>(&newMasterRec), sizeof(newMasterRec));
    thereIsARecord = false;
  }      
  else if (thereIsARecord) // must be a cancellation
  {
    // do whatever is wanted for cancellations
  }
  if (oldMasterRec.key <= updateRec.key)
    smallestKey = oldMasterRec.key;
  else
    smallestKey = updateRec.key;
  cancelFlag = false;
}

OldMaster.close();
updates.close();
newMaster.close();


}
