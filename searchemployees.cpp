	 
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
// prototypes
void showMenu();

//void readinfile( employees[], int &);
main()
{
 // cout<<"hello world"<<endl;
 employees person[1000];
 int input;
 int count;
   int position =0;
  // read in file
     ifstream infile;
   infile.open("employeesrec.dat", ios::binary | ios::in);
  while (!infile.eof())
   {  infile.read (reinterpret_cast <char*>(&person), sizeof(person));

    if (infile.eof())
      break;
    count++;
   }
   infile.close();

  showMenu();
  cin>>input;
  do {
  char userinput;
    switch(input)
    {
    case 1:
    {
     cout<<"Please Enter A Salary: ";
      int usersalary =0;
      cin>> usersalary;
       cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
      bool found = false;
      for(int i =0; i<= 1000; i++)
         {
             if(usersalary<= person[i].salary)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }


    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
			<<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
			<<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }





        }
     break;
    }
   case 2:
    {
      position =0;    
    cout<<"Please Enter A City Name: ";
    char usercity[41]=" ";
     cin>>usercity;
  

    
     // setting up table
      cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;

  

        
    bool found = false;
    
    for(int i =0; i <1000; i++)
     {
      if(strcmp(usercity,person[i].city) == 0)
         {
          // cout<<"here"<<endl;
           found = true;
           
  	 }
     else
	{
	 continue;
	}
    

    if(found == true)
     {
       
       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
			setw(14)<<person[i].address<<setw(18)<<person[i].city<<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
			<<person[i].fname<<person[i].lname<<person[i].email<<endl; 
     }
    
   }
    
   }
   
 // search by titles  
case 3:
{
    cout<<"Please Enter a Title: ";
    char usertitle[6] = " ";
    cin>> usertitle; 
      // setting up table
      cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
   bool found = false;

    for(int i =0; i <1000; i++)
     {
      if(strcmp(usertitle,person[i].title) == 0)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }
   


    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
                        <<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
                        <<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }
  

}
break;

}
// search by last name
case 4:
{
  cout<<"Please enter a Last Name: ";
   char userlastname[31] = " ";
   cin>> userlastname;  
     cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
   bool found = false;

    for(int i =0; i <1000; i++)
     {
      if(strcmp(userlastname,person[i].lname) == 0)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }



    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
                        <<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
                        <<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }


}
break;


}
// search by states
 case 5:
{
  
  cout<<"Please enter a State: ";
   char userstate[3] = " ";
   cin>> userstate;
     cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
   bool found = false;

    for(int i =0; i <1000; i++)
     {
      if(strcmp(userstate,person[i].state) == 0)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }



    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
                        <<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
                        <<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }


}
break;
}
// search  by zipcode
case 6:
{
  cout<<"Please enter a Zip Code: ";
   char userzip[6] = " ";
   cin>> userzip;
     cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
   bool found = false;

    for(int i =0; i <1000; i++)
     {
      if(strcmp(userzip,person[i].zipcode) == 0)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }



    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
                        <<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
                        <<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }


}
break;
}
case 7:
{
  cout<<"Please Enter A Age: ";
      int userage =0;
      cin>> userage;
       cout<<setw(1)<<left<<"Title"<<"  "<<setw(9)<<"First"<<setw(12)<<"Last"<<setw(20)<<"Address"<<" "<<setw(18)<<"City"<<setw(8)<<"State"<<setw(8)<<"Zip"<<
      setw(6)<<"Age"<<setw(13)<<"Salary"<<setw(32)<<"Email"<<endl;
      cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;
      bool found = false;
      for(int i =0; i<= 1000; i++)
         {
             if(userage<= person[i].age)
         {
          // cout<<"here"<<endl;
           found = true;

         }
     else
        {
         continue;
        }


    if(found == true)
     {

       cout << setw(7) << left << person[i].title<<setw(9)<<person[i].fname<<setw(12)<<person[i].lname<<setw(6)<<person[i].streetnum<<" "<<
                        setw(14)<<person[i].address<<setw(18)<<person[i].city
                        <<setw(8)<<person[i].state<<setw(8)<<person[i].zipcode<<setw(6)<<person[i].age<<setw(13)<<person[i].salary
                        <<person[i].fname<<person[i].lname<<person[i].email<<endl;
     }





        }


break;






}




 } // switch
 }// do loop
while(input!=8);

return 0;

}

 
// menu 
void showMenu()
{
 cout<<"Please Choose an Option from Below"<<endl;
 cout<<"-----------------------------------"<<endl;
  cout<<"1. Search by Salaries"<<endl;
  cout<<"2. Search by Cities"<<endl;
  cout<<"3. Search by Titles"<<endl;
  cout<<"4. Search by Last Names"<<endl;
  cout<<"5. Search by State"<<endl;
  cout<<"6. Search by Zipcode"<<endl;
  cout<<"7. Search by Age"<<endl;
  cout<<"8.Quit"<<endl;
  cout<<"Choice: ";
}
// search for city

