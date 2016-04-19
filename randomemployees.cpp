#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <stdio.h>  
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

int main ()
{  
      employees person;
     ofstream outfile;
     int numemployees = 1000;
     srand (time(NULL)); 


	// titles
	char randomtitles[8][7]={"Dr.","Mr.","Mr.","Mrs.","Mrs.","Ms.","Ms.","Rvd."};


	// first names
   char randomfname[80][31] ={"John","James","Robert","William","Kevin","Paul","Frank","Scott","Dennis","Dylan",
				 "Eric","Joe","Colton","Matt","Cody","Kyle","Trace","Shawn","Taylor","Adam",
				 "Gary","Brian","Frank","Dennis","Raymond","Jack","Jose","Harry","Draco","Ron",
				 "Fred","George","Nevile","Ryan","Luke","Trevor","Larry","Geno","Blake","Chris",
				"Connie","Brittany","Elizabeth","Deborah","Abigail","Patty","Molly","Michelle","Jessica","Emily",
                                "Judy","Janice","Karen","Hannah","Katie","Lori","Megan","Sarah","Christine","Caroline",
				"Ginny","Luna","Daisy","Polly","Jennie","Sam","Amy","Paige","Susaun","Ann",
				"Janet","Jean","Julie","Alice","Kelly","Laura","April","June","Wanda","Ethel"};
	// Last Names
 char randomlname[80][31]  ={"Smith","Potter","Rempala","Wallo","Weasley","Keene","Whiteman","Toutant","Malfoy","Kane",
                                 "Minaker","Rausch","Fields","Hartman","Wilson","Johnson","Williams","Hill","Scott","Baker",
                                 "Longbottom","Dumbledore","Lovegood","Carlson","Perez","Evans","Bones","Turner","Randcliff","Li",
                                 "Sun","Dotski","Hart","Reed","Bonner","Steller","Friedline","Cook","Jobs","Gates",
                                "James","Roda","Moody","Snape","Genovia","Howard","Bell","Kroger","Meijer","Xiu",
                                "June","Wentz","Stump","Archer","Ross","Winchester","Jenkins","Mosbey","Pickles","Thornberry",
                                "Cox","Kelly","Senders","Sanders","Verlander","Microsoft","Bevridge","Long","Ford","Chevy",
                                "Mason","Boyd","Sherman","Keys","Spears","Hunt","Black","Ray","Palmers","Daniels"};

	//  Street Names
 char randomstreetname[80][31]={"Oaks","Lake","River","Wombat","Walrus","Kleene","Slytherin","Gryfindor","Hufflepuff","Ravenclaw",
                                 "Gaffke","Bestie","Jane","Easterday","Hughes","Stream","Pines","Hill","Hogwarts","Kennedy",
                                 "LakeShore","LakeView","SouthLake","Flower","Ocean","Tree","Bones","Wind","Rain","Moon",
                                "Sun","Dotski","Hart","Reed","Bonner","Steller","Friedline","Cook","Jobs","Gates",
                                "Plute","Walabey","Sherman","Horse","Apple","Pear","Orange","Turnip","Stone","Java",
                                "Perl","Java","Lua","LSSU","Sunny","Sunshine","Storm","Thunder","Lighting","High",
                                "Salad","Noodles","Bread","Vodka","Tigers","Lions","Bears","Short","Giraff","Dolphin",
                                "Beer","Party","May","July","December","November","Friday","Monday","Thursday","Troll"};
 // city names
 char randomcitynames[10][31] = {"St.Clair Shores","Sault Ste. Marie","Detroit","New York City","Chicago","Los Angeles",
 				   "Orlando","Nashville","Cleveland","Grand Rapids"};
 char randomemails [5][31] =  {"@gmail.com","@yahoo.com","@aol.com","@clever.com","@outlook.com"};






           int streetnums =0;
	   int ages =0;
           int money = 0;           
          //cout<<streetnum<<endl;  
           outfile.open("employeesrec.dat", ios::binary | ios::out);
        for(int i =0; i <=numemployees; i++)
{
 
              streetnums = 1000 + rand() % 9000;
              ages= 18 + rand()%60;
              money = 100000 + rand()%123456;
			



                      sprintf(person.title, randomtitles[rand()%8]);
                      sprintf(person.fname, randomfname[rand()%80]);
     		     sprintf(person.lname, randomlname[rand()%80]);
		            person.streetnum = streetnums;
		     sprintf(person.address,randomstreetname[rand()%80]);
               string temp =  randomcitynames[rand()%10];
                   if(temp == "St.Clair Shores")
			{
 			    sprintf(person.city,"St.Clair Shores");
                             sprintf(person.state, "MI");
			    sprintf(person.zipcode,"48081");


			}
                  if(temp=="Sault Ste. Marie")
			{
			     sprintf(person.city,"Sault Ste. Marie");
                             sprintf(person.state, "MI");
                            sprintf(person.zipcode,"49783");

			}
                       if(temp=="Detroit")
			{
			    sprintf(person.city,"Detroit");
                             sprintf(person.state, "MI");
                            sprintf(person.zipcode,"48224");
			}
			 if(temp=="New York City")
                        {
                            sprintf(person.city,"New York City");
                             sprintf(person.state, "NY");
                            sprintf(person.zipcode,"10001");
                        }
			if(temp=="Chicago")
                        {
                            sprintf(person.city,"Chicago");
                             sprintf(person.state, "IL");
                            sprintf(person.zipcode,"60290");
                        }
			 if(temp=="Los Angeles")
                        {
                            sprintf(person.city,"Los Angeles");
                             sprintf(person.state, "CA");
                            sprintf(person.zipcode,"90005");
                        }
		        if(temp=="Orlando")
                        {
                            sprintf(person.city,"Orlando");
                             sprintf(person.state, "FL");
                            sprintf(person.zipcode,"32805");
                        }
			 if(temp=="Nashville")
                        {
                            sprintf(person.city,"Nashville");
                             sprintf(person.state, "TN");
                            sprintf(person.zipcode,"37206");
                        }


			  
                         if(temp=="Cleveland")
                        {
                            sprintf(person.city,"Cleveland");
                             sprintf(person.state, "OH");
                            sprintf(person.zipcode,"44101");
                        }

			  if(temp=="Grand Rapids")
                        {
                            sprintf(person.city,"Grand Rapids");
                             sprintf(person.state, "MI");
                            sprintf(person.zipcode,"49505");
                        }
                         
                           
               
                           
			   sprintf(person.email,randomemails[rand() % 5]);
                          person.age = ages;						
                          person.salary = money;
                  






		 outfile.write (reinterpret_cast <char*>(&person), sizeof(person));
  			
}
  outfile.close();
 















return 0;
}
  



