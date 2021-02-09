#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class CaffeineBeverageWithHook
{
  protected:
  
    virtual void boilWater() const
    {
        
        cout<<"Boiling Water"<<endl;
    }
    virtual void pourInCup() const
    {
        cout<<"물에 붓는중"<<endl;
    }
    virtual bool customerWantsCondiments()
    {
        return true;
    }
    
    
    public:
    
    virtual ~CaffeineBeverageWithHook()
    {
        cout<<"카페인 비버리지 소멸"<<endl;
    }
    virtual void prepareRecipe()
    {
        boilWater();
        brew();
        pourInCup();
        if(customerWantsCondiments())
            addCondiments();
    }
    virtual void brew() const = 0;
    virtual void addCondiments() const = 0;
    
};

class TeaWithHook : public CaffeineBeverageWithHook
{
    string getUserInput() const
    {
        cout<<"레몬을 넣어드릴까요? (y/n)"<<endl;
        string k;
        cin>>k;
        transform(k.begin(), k.end(), k.begin(), ::tolower);
        return k;
    }
    
    public:
    void brew() const
    {
        cout<<"차를 우려내는중입니다"<<endl;
    }
    void addCondiments() const
    {
        cout<<"레몬을 넣는중입니다"<<endl;
    }
    bool customerWantsCondiments()
    {
        bool val =false;
        string ans = getUserInput();
        if(ans.find('y')!=ans.npos)
            val = true;
        return val;
    }
    
    
};

class CoffeeWithHook : public CaffeineBeverageWithHook
{
    string getUserInput() const
    {
        string k;
        cout<<"설탕과 우유를 넣어드릴까요? (y/n)"<<endl;
        cin>>k;
        transform(k.begin(), k.end(), k.begin(), ::tolower);
        return k;
    }
    
    public:
    void brew() const
    {
        cout<<"커피를 필터를 통해 내리고있습니다"<<endl;
    }
    void addCondiments() const
    {
        cout<<"설탕과 우유를 넣어줍니다"<<endl;
    }
    bool customerWantsCondiments()
    {
        bool val = false;
        string ans = getUserInput();
        if(ans.find('y')!=ans.npos)
            val =true;
        return val;
    }
    
    
};




int main()
{
    
    
    unique_ptr<TeaWithHook> tea(new TeaWithHook());
    unique_ptr<CoffeeWithHook> coffee(new CoffeeWithHook());
    
    cout<<"차를 만듭니다"<<endl;
    tea->prepareRecipe();
    
    cout<<"커피를 만듭니다"<<endl;
    coffee->prepareRecipe();
    
    return 0;
    
    
    
}
