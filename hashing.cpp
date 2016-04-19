#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#define TableSize 150
#define MaxWordSize 33
float total =0;
struct Entry
{
  char Word[MaxWordSize];
  int  Freq;
  float  Probes;
  
};

int main()
{
  char     FName[81];
  ifstream In;
  ofstream Out;
  Entry    Table[TableSize];
  char     InWord[MaxWordSize];
 float average =0; 
  bool getWord (ifstream &In, char Word[]);
  void Store (char Word[], Entry Table[]);
  void doReport (ofstream &Out, Entry Table[]);

  for (int i = 0; i < TableSize; i++)
   {
    Table[i].Freq = -1;
    Table[i].Word[0] = '\0';
    Table[i].Probes = 0;
   
   }
  cout << "Where's the input? ";
  cin.getline (FName, 81);
  In.open (FName);

  cout << "Where should the output go? ";
  cin.getline (FName, 81);
  Out.open (FName);

  while (getWord (In, InWord))
    Store (InWord, Table);


average =total/272;
cout<<average;
  doReport (Out, Table);
  


return 0;
}

bool getWord (ifstream &In, char Word[])
{
  char Next = '\0';
  int  Size = 0;
  Word[Size] = '\0';
  
 

  while (!In.eof())
  {
    In.get(Next);
    
    if (isalpha(Next))
      break;
  }
  if (Next == '\0') return false;
  do
  {
    if (Size < MaxWordSize - 1)
{
      Word[Size++] = char(toupper(Next));
}
    if (In.eof())
      break;
    In.get (Next);
  }
  while (isalpha (Next));
{
  
  Word[Size] = '\0';
}
  return true;
}

void Store (char Word[], Entry Table[])
{
  int Hash(char Word[]);
 
  int Probes = 1;
  int Loc = Hash(Word);
  do
  {
    if (Table[Loc].Freq < 0)
    {
      strcpy (Table[Loc].Word, Word);
      Table[Loc].Freq = 1;
      Table[Loc].Probes = Probes;
             
      return;
    }
    if (strcmp(Table[Loc].Word, Word) == 0)
    {
      Table[Loc].Freq++;
      return;
	
    }
    total ++;
    Probes++;
	
    Loc = (Loc+1) % TableSize;
   }
   while (true);
  
}

int Hash (char Word[])
{
  unsigned int Fold (char Word[]);

  return (Fold(Word) % TableSize);
}

unsigned int Fold (char Word[])
{
  int Size = strlen(Word);
  unsigned int Result = 0;
  for (int p = 0, Shift = 0; p < Size; p++)
  {
    Result ^= (unsigned int)(Word[p]) << Shift;
    Shift++;
    if (Shift >= 24) Shift = 0;
  }
  return Result;
}

void doReport (ofstream &Out, Entry Table[])
{ 
  
  for (int i=0; i<TableSize; i++)
    Out << i << ": " << Table[i].Word << "  " << Table[i].Freq << "  " << Table[i].Probes<<  endl;
   
  
}


