#include <iostream>


using namespace std;

class ChocolateBoiler
{
private:
bool empty;
bool boiled;
ChocolateBoiler(){empty=true; boiled=false;}
static ChocolateBoiler* uniqueInstance;
ChocolateBoiler(const ChocolateBoiler&) = delete;
void operator=(const ChocolateBoiler&) = delete;



public:

~ChocolateBoiler(){uniqueInstance=nullptr;}

static ChocolateBoiler* getInstance()
{
if(uniqueInstance==nullptr)
{
cout<<"Unique Instance is nullptr. so Create!"<<endl;
uniqueInstance = new ChocolateBoiler();
}
cout<<"Return Unique Instance."<<endl;
return uniqueInstance;
}

void fill()
{
if(isEmpty())
{
empty=false;
boiled=false;
}
}

void drain()
{
if(!isEmpty() && isBoiled())
{
empty=true;
}
}

void boil()
{
if(!isEmpty() && !isBoiled())
{
boiled=true;
}
}



bool isEmpty() const
{
return empty;
}

bool isBoiled() const
{
return boiled;
}




};

ChocolateBoiler*
ChocolateBoiler::uniqueInstance=nullptr;

int main()
{
    ChocolateBoiler* boiler = ChocolateBoiler::getInstance();
    boiler->fill();
    boiler->boil();
    boiler->drain();
    
    
    ChocolateBoiler* boiler2 = ChocolateBoiler::getInstance();
    
    if( boiler == boiler2 )
    std::cout << "Got same boiler" << std::endl;
  else
    std::cout << "Oh oh! got a different boiler" << std::endl;
    
}


