#include <array>
#include <map>
using namespace std;




unsigned fruit(const array<vector<string>, 3> &reels, const array<unsigned, 3> &spins)
{
  
    map<string, int> fruit;
  
    vector<string> res = {"Wild", "Star", "Bell", "Shell", "Seven", "Cherry", "Bar", "King", "Queen", "Jack"};
  
    for(auto i : res)
      fruit[i]=0;
  
  
    for(int i=0;i<3;i++)
      fruit[reels[i][spins[i]]]++;
  
    if(fruit["Wild"]==3)
      return 100;
    else if(fruit["Wild"]==2)
      return 10;
    
    if(fruit["Star"]==3)
      return 90;
    else if(fruit["Star"]==2 && fruit["Wild"]==0)
      return 9;
    else if(fruit["Star"]==2 && fruit["Wild"]==1)
      return 18;
  
  
     if(fruit["Bell"]==3)
      return 80;
    else if(fruit["Bell"]==2 && fruit["Wild"]==0)
      return 8;
    else if(fruit["Bell"]==2 && fruit["Wild"]==1)
      return 16;
      
  
  if(fruit["Shell"]==3)
      return 70;
    else if(fruit["Shell"]==2 && fruit["Wild"]==0)
      return 7;
    else if(fruit["Shell"]==2 && fruit["Wild"]==1)
      return 14;
      
  if(fruit["Seven"]==3)
      return 60;
    else if(fruit["Seven"]==2 && fruit["Wild"]==0)
      return 6;
    else if(fruit["Seven"]==2 && fruit["Wild"]==1)
      return 12;
  
     if(fruit["Cherry"]==3)
      return 50;
    else if(fruit["Cherry"]==2 && fruit["Wild"]==0)
      return 5;
    else if(fruit["Cherry"]==2 && fruit["Wild"]==1)
      return 10; 
  
  if(fruit["Bar"]==3)
      return 40;
    else if(fruit["Bar"]==2 && fruit["Wild"]==0)
      return 4;
    else if(fruit["Bar"]==2 && fruit["Wild"]==1)
      return 8; 
  
  if(fruit["King"]==3)
      return 30;
    else if(fruit["King"]==2 && fruit["Wild"]==0)
      return 3;
    else if(fruit["King"]==2 && fruit["Wild"]==1)
      return 6; 
    
    if(fruit["Queen"]==3)
      return 20;
    else if(fruit["Queen"]==2 && fruit["Wild"]==0)
      return 2;
    else if(fruit["Queen"]==2 && fruit["Wild"]==1)
      return 4; 
  
    if(fruit["Jack"]==3)
      return 10;
    else if(fruit["Jack"]==2 && fruit["Wild"]==0)
      return 1;
    else if(fruit["Jack"]==2 && fruit["Wild"]==1)
      return 2; 
  
  
  
    return 0; // Code here
}
