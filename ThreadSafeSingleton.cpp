
#include <iostream>
#include <memory>
#include <mutex>

using namespace std;



  class Singleton {
  public:
    static std::shared_ptr<Singleton> GetInstance();
    ~Singleton() = default;
  private:
    Singleton() = default;
    static std::shared_ptr<Singleton> instance;
    static std::mutex singletonMutex;
  };

std::shared_ptr<Singleton> Singleton::instance;
 std::mutex Singleton::singletonMutex;

  std::shared_ptr<Singleton> Singleton::GetInstance()
  {
    if(instance == nullptr)
    {
      cout<<"mutex lock"<<endl;
      std::lock_guard<std::mutex> lk(singletonMutex);
      if(instance == nullptr)
      {
        cout<<"객체 생성"<<endl;
        instance.reset(new Singleton());
      }
    }
    cout<<"객체를 반환합니다"<<endl;
    return instance;
  }






int main()
{
  
  std::cout << "*************** Thread-safe classic Singleton using shared_ptr *************" << std::endl;
  try
  {
      Singleton::GetInstance();
      //Singleton::GetInstance();
     // Singleton::GetInstance();
      
      return 0;
  }catch(exception& e)
  {
      cout<<e.what()<<endl;
  }
  
}
