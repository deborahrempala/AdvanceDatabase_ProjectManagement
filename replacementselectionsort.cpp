// CSCI 411
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int N=500;

struct PersonType {
  int  key;
  char first[10];
  char last[20];
  char address[30];
  char startDate[12];
  char endDate[12];
};

main()
{
  fstream infile,outfile;
  char filename[20];
  PersonType person[N], temp;
  infile.open("Master24.dat", ios::binary | ios::in);

  int filenum = 0;
  int spot;
  int currSmallest=0;
  bool done=false;
  int count =0;
  sprintf(filename, "%s%d%s", "outfile", filenum, ".dat"); 

  outfile.open(filename, ios::binary | ios::out);
while(!infile.eof())
{
  for (int i=0; i<N; i++)
   {
    infile.read (reinterpret_cast <char*>(&person[i]), sizeof(person[i]));
//    cout << person[i].key << " ";
   }



  for (int i=1; i<=N; i++)
    for (int j=0; j<N-1; j++)
      if (person[j].key > person[i].key)
        {
          temp = person[j];
          person[j] = person[i];
          person[i] = temp;
        }

    while (currSmallest < N)
     {
       outfile.write (reinterpret_cast <char*>(&person[currSmallest]), sizeof(person[currSmallest]));
       infile.read(reinterpret_cast <char*>(&temp), sizeof(temp));
       if (temp.key < person[currSmallest].key)
         {
           spot = currSmallest-1;
           while ((person[spot].key > temp.key) && (spot >= 0))
            {
              person[spot+1] = person[spot];
              spot--;
            }
           person[spot+1] = temp;
           currSmallest++;
         }
      else
        {
          spot = currSmallest+1;  
          while ((person[spot].key < temp.key) && (spot <= N-1))
           {
             person[spot-1] = person[spot];
             spot++;
           }
          person[spot-1] = temp;
        }
    //count --;

     }

    outfile.close();
	
cout<<count<<endl;
}
  infile.close();
  return 0;
}
