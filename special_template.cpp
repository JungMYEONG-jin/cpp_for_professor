#include <iostream>

using namespace std;

enum class Fruit{apple,orange,pear};
enum class Color{red,green,orange};



template<typename T> struct Traits;


template<> struct Traits<Fruit>
{
  static string name(int i)
  {
    if(i==static_cast<int>(Fruit::apple))
      return "apple";
    if(i==static_cast<int>(Fruit::orange))
      return "orange";
    if(i==static_cast<int>(Fruit::pear))
      return "pear";
    else
      return "unknown";
      
  }
};


template<> struct Traits<Color>
{
  static string name(int i)
  {
    if(i==static_cast<int>(Color::red))
      return "red";
    if(i==static_cast<int>(Color::orange))
      return "orange";
    if(i==static_cast<int>(Color::green))
      return "green";
    else
      return "unknown";
      
  }
};




