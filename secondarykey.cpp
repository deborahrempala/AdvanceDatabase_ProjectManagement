#include<fstream>
#include<iostream>
#include <cstring>

using namespace std;
 struct StudentType {
	char studentID[12];
	char first[10];
	char last[20];
	char address[30];
	char city[30];
	char state[20];
	int credits;
	int age;
	double gpa;
};

// city structure
struct CitySearch {
	
	char StudentID[12][30];
	char city[30];
};

// gpa structure
struct GPASearch {
	
	char StudentID[12][30];
	double gpa;
};

// age structure
struct AgeSearch {
	
	char StudentID[12][30];
	int age;
};

// main program
int main()
{
  // intialize structs
  StudentType Student;
  CitySearch city;
  GPASearch gpa;
  AgeSearch age;
  int count =0;
  // file variables
   fstream inFile;
 // read files
   infile.open("Students25.dat", ios::binary | ios::in);
    while (!infile.eof())
   {
    infile.read (reinterpret_cast <char*>(&Student), sizeof(Student));
    count ++;
   }    	
// city
   // grab city from student structure
	// search city structure
	 // if city exists then add id to structure
	// if it doesn't exist add city and id to structure

 //GPA
	// grab gpa from student structure
	//search gpa structure
	// if gpa exist add id to structure
	// if it doesn't exist add gpa and id to structure

// Age
	// grab age from student structure
	// search age structure
	// if age exist add id to structure
	// if it doesn't exist add age and id to structure

// searching






} 

