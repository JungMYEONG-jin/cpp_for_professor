#include <string>
#include <vector>
#include <map>
using namespace std;
std::string format_duration(int seconds) {
    // your code here
    string res = "";
    map<int, string> time;
    if (seconds == 0)
        return "now";
    // 0 year 1 day 2 hour 3 min 4 sec
    int count = 0;
    while (seconds > 0)
    {
        if (count == 0)
        {
            int sec = seconds % 60;
            if (sec == 1)
                time[4] = to_string(sec) + " second";
            else if(sec>1)
                time[4] = to_string(sec) + " seconds";

        }

        if (count == 1)
        {
            int min = seconds % 60;
            if (min == 1)
                time[3] = to_string(min) + " minute";
            else if(min>1)
                time[3] = to_string(min) + " minutes";
        }

        if (count == 2)
        {
            int hour = seconds % 24;
            if (hour == 1)
                time[2] = to_string(hour) + " hour";
            else if(hour>1)
                time[2] = to_string(hour) + " hours";
        }
        if (count == 3)
        {
            cout<<seconds<<endl;
            int day = seconds % 365;
            if (day == 1)
                time[1] = to_string(day) + " day";
            else if(day>1)
                time[1] = to_string(day) + " days";
        }
        if (count == 4)
        {
            cout<<seconds<<endl;
            int year = seconds;
            if (year == 1)
                time[0] = to_string(year) + " year";
            else if(year>1)
                time[0] = to_string(year) + " years";

        }
        if (count<=1)
          {
          seconds/=60;
          count++;
        
      
        }
      else if(count<=2)
        {
        seconds/=24;
        count++;
        
      }else
        {
        seconds/=365;
        count++;
      }

}

    if (time.size() == 1)
    {
        for (auto it : time)
            res += it.second;
        return res;
    }
    else if (time.size() == 2)
    {
        for (auto it : time)
            res += it.second + " and ";
        cout << res.substr(0, res.size() - 5) << endl;
        return res.substr(0, res.size() - 5);
    }
    else if (time.size() >= 3)
    {
        int k = 0;
        for (auto it : time)
        {
            if (time.size() - k == 2)
                res += it.second + " and ";
            else
                res += it.second + ", ";
            k++;
        }
        return res.substr(0,res.size()-2);
    }

    return res;

}


/* BEST CODE

#include <string>
#include <vector>

std::string format_duration(int seconds) {
  if (seconds == 0) return "now";
  
  std::vector<std::string> times;
  auto add = [&] (auto text, auto time) {
    if (time == 0) return;
    times.push_back(std::to_string(time) + text + (time > 1 ? "s" : ""));
  };
  add(" year",    seconds / 31536000);    
  add(" day",    (seconds / 86400) % 365);    
  add(" hour",   (seconds / 3600) % 24);    
  add(" minute", (seconds / 60) % 60);    
  add(" second",  seconds % 60);    
  
  std::string result = times[0];
  for (auto i = 1; i < times.size() - 1; i ++) result.append(", " + times[i]);
  if (times.size() > 1) result.append(" and " + times.back());
  
  return result;
}












*/
