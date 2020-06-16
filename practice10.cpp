#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    public:
    void set_age(int age)
    {
        s_age=age;
    }
    void set_standard(int standard)
    {
        s_std=standard;
    }
    void set_first_name(string first)
    {
        s_first=first;
    }
    void set_last_name(string last)
    {
        s_last=last;
    }
    int get_age()
    {
        return s_age;
    }
    int get_standard()
    {
        return s_std;
    }
    string get_first_name()
    {
        return s_first;
    }
    string get_last_name()
    {
        return s_last;
    }
    string to_string()
    {
        stringstream ss;
        ss<<s_age<<","<<s_first<<","<<s_last<<","<<s_std<<endl;
        return ss.str();
    }


    private:
    int s_age;
    int s_std;
    string s_first;
    string s_last;
};









int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
