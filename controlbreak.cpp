#include <iostream>

#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

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

void mysort (employees person[], int );


main()
{
 int num;
  employees person[1000];
   int count;
   int mimin =0;
   int mimax =0;
   float miaverage =0;
   int mitotal = 0;
   int totalcount =0;
   char mi[3] = "MI";
// scs variables
int scstotal =0;
int scsmin =0;
int scsmax =0;
int scscount =0;
float scsaverage =0;
// gr variables
int grtotal =0;
int grmin =0;
int grmax =0;
int grcount=0;
float graverage =0;
// read in binary file 
   ifstream infile;
   ofstream out;
   infile.open("employeesrec.dat", ios::binary | ios::in);
    out.open("report.txt",ios::out);
    employees temp;
  while (!infile.eof())
   {  infile.read (reinterpret_cast <char*>(&person), sizeof(person));

    if (infile.eof())
      break;
    count++;
// sort person structure
  mysort(person,count);
   }
out<<setw(10)<<"City/State"<<setw(20)<<"Min."<<setw(20)<<"Max."<<setw(10)<<"Avg"<<endl;
out<<setw(10)<<"----------"<<setw(20)<<"-----"<<setw(20)<<"-----"<<setw(10)<<"-----"<<endl;
 for(int i =0; i <= 1000; i ++)
{
   if(strcmp(mi,person[i].state)==0)  
     {
        //out<<"State:MI"<<endl;   
         mitotal = mitotal  + person[i].salary;
         totalcount ++;
                for(int j =0; j<=1000; j++)
                  {
                     if(person[0].salary < person[j].salary)
               		 mimax = person[j].salary;
                 if(person[j].salary >person[0].salary)
                         mimin = person[j].salary;
                 }
      }
if(strcmp("St.Clair Shores",person[i].city)==0)
     {
       
        //out<<"State:MI"<<endl;
         scstotal = scstotal  + person[i].salary;
         scscount ++;
                for(int k =0; k<=1000; k++)
                  {
                     if(person[0].salary < person[k].salary)
                         scsmax = person[k].salary;
                 if(person[k].salary >person[0].salary)
                         scsmin = person[k].salary;     
                 }  

     }  

      
if(strcmp("Grand Rapids",person[i].city)==0)
     {

        //out<<"State:MI"<<endl;
         grtotal = grtotal  + person[i].salary;
         grcount ++;
                for(int k =0; k<=1000; k++)
                  {
                     if(person[0].salary < person[k].salary)
                         grmax = person[k].salary;
                 if(person[0].salary >person[k].salary)
                         grmin = person[k].salary;

	        }

     }

  


}
   miaverage = mitotal/totalcount;
   scsaverage = scstotal/scscount;
   graverage = grtotal/grcount;
   out<<setw(10)<<"State: MI"<<setw(20)<<mimin<<setw(20)<<mimax<<setw(10)<<miaverage<<endl;
   out<<setw(10)<<"SCS,MI"<<setw(20)<<scsmin<<setw(20)<<scsmax<<setw(10)<<scsaverage<<endl;
   out<<setw(10)<<"GR,MI"<<setw(20)<<grmin<<setw(20)<<grmax<<setw(10)<<graverage<<endl;


   infile.close();




return 0;
}

void mysort(employees person[], int num)
{
	employees temp;
	for(int i =0; i< 1000; i++)
		for(int j =i+1; j <1000; j++)
			if( (strcmp(person[i].state,person[j].state) > 0) ||
			((strcmp(person[i].state,person[j].state)==0) &&
			  (strcmp(person[i].city,person[j].city) > 0)))
			{
			 	temp = person[i];
				person[i] = person[j];
				person[j] = temp;
			}
         //for(int i =0; i < 1000; i++)
	//cout<<person[i].lname<<"   "<<person[i].state<<endl;	



}
