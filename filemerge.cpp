#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

struct CustomerType {
int key;
char first[20];
char last[20];
char address[30];
char startDate[12];
char endDate[12];
};


main ()
{
	const int NUM_FILES = 8;
	char filename[20];
	ofstream outFile;
	int smallKey  = 1000000;
	int smallIndex = NUM_FILES + 1;
	int lastkey =  79950;
	outFile.open("NewMaster1.dat", ios::out);
	ifstream* inFile = new ifstream[NUM_FILES];
	for(int i =0; i<NUM_FILES; i++)
		{
			sprintf(filename,"OldMaster%d.dat",i);
			inFile[i].open(filename,ios::binary | ios::in);
		}

	// read in the first record
	CustomerType* inRec = new CustomerType[NUM_FILES];
	CustomerType newMasterRec;
	
	for(int i=0; i <NUM_FILES; i++)
	{
		inFile[i].read(reinterpret_cast<char*>(&inRec[i]), 
		sizeof(inRec[i]));
		
	}
	// find smallest key 
	for(int i =0; i< NUM_FILES; i++)
	{
		if(inRec[i].key < smallKey)
		{
			smallKey = inRec[i].key;
			smallIndex = i;
		}
	}

	while(inRec[smallIndex].key != lastkey)
	{
		newMasterRec = inRec[smallIndex];
		outFile.write(reinterpret_cast<char*>(&newMasterRec),
		sizeof(newMasterRec));
		 inFile[smallIndex].read(reinterpret_cast<char*>(&inRec[smallIndex]),
                sizeof(inRec[smallIndex]));
		smallKey = inRec[0].key; smallIndex =0;
		for(int i =1; i < NUM_FILES; i++)
		{
			
			if(inRec[i].key <= smallKey)
			{
				smallKey = inRec[i].key;
				smallIndex = i;
			}
		}
	cout<<"Last key record "<< lastkey << " smallKey "<<smallKey<<endl;
	
	}
// closing files 
	for(int i =0; i <NUM_FILES; i ++)
	{
		sprintf(filename,"OldMaster%d.dat", i);
		inFile[i].close();
	
	}


	
return 0;
}

