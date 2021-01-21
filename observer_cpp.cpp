#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <memory>


using namespace std;


class Observer{
    
public:

  //Observer();
  virtual ~Observer() = default;
  
  virtual void update(float temp, float hum, float press) = 0;
    
};




class Subject
{
    
public:

 // Subject();
  virtual ~Subject() = default;
  Subject();
  virtual void registerObserver(Observer* o) = 0;
  virtual void removeObserver(Observer* o) = 0;
  virtual void notifyObservers() = 0;
  
    
    
    
};

Subject::Subject(){}

class WeatherData : public Subject
{
  
  private:
  float hum;
  float temper;
  float press;
  vector<Observer*> mObserver;
 
  
  public:
  
  WeatherData();
  
  void SetChanged(float hum, float temper, float press)
  {
      this->hum = hum;
      this->temper = temper;
      this->press = press;
      MeasurementChanged();
      
  }
  
  void registerObserver(Observer* o)
  {
      mObserver.push_back(o);
  }
  
  void removeObserver(Observer* o)
  {
      auto it = find(mObserver.begin(), mObserver.end(), o);
      if(it!=mObserver.end())
        mObserver.erase(it);
  }
  
  
  void MeasurementChanged()
  {
      notifyObservers();
  }
  
  void notifyObservers()
  {
      
      for(auto* it : mObserver)
      {
          it->update(temper, hum, press);
          
      }
      
  }
    
    
};


WeatherData::WeatherData(){};





class CurCondition : public Observer
{
    private:
    
    Subject* w;
    float temper;
    float press;
    float hum;
    
    public:
    //CurCondition();
    CurCondition(Subject* weather);
    CurCondition();
    
    ~CurCondition();
    
    
    void update(float temper, float hum, float press)
    {
        this->temper = temper;
        this->hum = hum;
        this->press = press;
        display();
        
    }
    
    
    
    
    
    void display()
    {
        cout<<"현재 압력: "<<press<<endl;
        cout<<"현재 온도: "<<temper<<endl;
        cout<<"현재 습도: "<<hum<<endl;
    }
    
    
    
    
    
    
    
    
    
    
};


CurCondition::CurCondition(Subject* weather)
    {
        w=weather;
        w->registerObserver(this);
    }

CurCondition::CurCondition(){}




int main()
{

    WeatherData* weather = new WeatherData();
    //*  c1 = new CurCondition(weather);
   CurCondition*  c2 = new CurCondition(weather);
    
    
    weather->SetChanged(26.0f, 77.0f, 33.0f);
    
    cout<<"remove obeserver"<<endl;
    
    weather->removeObserver(c2);
    
   weather->SetChanged(5.0f, 1, 13.0f);
    
    return 0;
    


    
    
}
