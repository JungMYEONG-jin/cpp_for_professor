#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

std::string catMouse(std::string field, unsigned int jump){
  //your code here
  
  auto it = field.find('C');
  auto mouse = field.find('m');
  auto dog = field.find('D');
  
  if(it==field.npos || mouse==field.npos || dog==field.npos)
    return "boring without all three";
  
  if(it>dog && mouse>dog) // dog left cat mouse right
  {
    int len = it-mouse;
    if(abs(len)<=jump)
      return "Caught!";
    else
      return "Escaped!";
  }
  if(it<dog && mouse<dog) // dog right cat mouse left
  {
    int len = it-mouse;
    if(abs(len)<=jump)
      return "Caught!";
    else
      return "Escaped!";
  }
  if(it>dog && mouse<dog) // mouse dog cat
  {
    int len = it-mouse;
    if(abs(len)<=jump)
      return "Protected!";
    else
      return "Escaped!";
  }
  if(it<dog && mouse>dog) // cat dog mouse
  {
    int len = it-mouse;
    if(abs(len)<=jump)
      return "Protected!";
    else
      return "Escaped!";
  }
  
  
  
  
  
}
