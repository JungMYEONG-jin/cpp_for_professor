#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <regex>
using namespace std;




string multiply(string a, string b)
{
    int len1 = a.size();
    int len2 = b.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in a 
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = a[i] - '0';

        // To shift position to left after every 
        // multiplication of a digit in b 
        i_n2 = 0;

        // Go from right to left in b              
        for (int j = len2 - 1; j >= 0; j--)
        {
            // Take current digit of second number 
            int n2 = b[j] - '0';

            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration 
            carry = sum / 10;

            // Store result 
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell 
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every 
        // multiplication of a digit in a. 
        i_n1++;
    }

    // ignore '0's from the right 
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // If all were '0's - means either both or 
    // one of a or b were '0' 
    if (i == -1)
        return "0";

    // generate the result string 
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    s = regex_replace(s, regex("^0+"), "");
    return s.length() ? s : "0";


    //return s;
}
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2 || n1 == n2 && str1 < str2)
        return true;
    if (n2 < n1 || n1==n2 && str1>str2)
        return false;

    if (str1 == str2)
        return true;

    return false;
}

// Function for find difference of larger numbers 
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result 
    string str = "";

    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings 
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i = 0; i < n2; i++)
    {
        // Do school mathematics, compute difference of 
        // current digits 

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number 
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive 
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string 
    reverse(str.begin(), str.end());

    str = regex_replace(str, regex("^0+"), "");
    return str.length() ? str : "0";

   // return str;
}


vector<string> longDiv(string a, string b)
{
    vector<string> res;
    string rem = "";
    string holder = "";


    for (int i = 0; i < a.size(); i++)
    {
        rem += a[i];
        int j = 0;
        while (isSmaller(multiply(b, to_string(j)), rem)) j++;
        holder += to_string(--j);
        rem = findDiff(rem, multiply(b, to_string(j)));
    }


    holder = regex_replace(holder, regex("^0+"), "");
    rem = regex_replace(rem,regex("^0+"), "");
    return vector<string> {holder.size() ? holder : "0", rem.size() ? rem : "0"};


   

    return res;


}




/*

//BESTCODE

vector<string> divide_strings(string a, string b) {
  function<string (string, string)> mul = [] (string a, string b) -> string {
    vector<int> v;
    for (int i = 0; i < a.length(); i++) v.push_back(((int)a[i] - 48) * stoi(b, nullptr, 10));
    for (int i = v.size() - 1; i > 0; i--) {
      v[i - 1] += v[i] / 10;
      v[i] %= 10;
    }
    string result = "";
    for (int i = 0; i < v.size(); i++) result += to_string(v[i]);
    result = regex_replace(result, regex("^0+"), "");
    return result.length() ? result : "0";
  }, sub = [] (string a, string b) -> string {
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    vector<int> v;
    for (int i = 0; i < a.length(); i++) v.push_back((int)a[i] - (int)b[i]);
    for (int i = v.size() - 1; i > 0; i--) if (v[i] < 0) {
      v[i] += 10;
      v[i - 1]--;
    }
    string result = "";
    for (int i = 0; i < v.size(); i++) result += to_string(v[i]);
    result = regex_replace(result, regex("^0+"), "");
    return result.length() ? result : "0";
  };
  function<bool (string, string)> lte = [] (string a, string b) -> bool {
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    if (a == b) return true;
    for (int i = 0; i < a.length(); i++) {
      if ((int)a[i] < (int)b[i]) return true;
      else if ((int)a[i] > (int)b[i]) return false;
    }
    return false;
  };
  string quotient = "", remainder = "";
  for (int i = 0; i < a.length(); i++) {
    remainder += a[i];
    int j = 0;
    while (lte(mul(b, to_string(j)), remainder)) j++;
    quotient += to_string(--j);
    remainder = sub(remainder, mul(b, to_string(j)));
  }
  quotient = regex_replace(quotient, regex("^0+"), "");
  remainder = regex_replace(remainder, regex("^0+"), "");
  return vector<string> {quotient.length() ? quotient : "0", remainder.length() ? remainder : "0"};
}

















*/




int main()
{
	

   
	{
		auto k = longDiv("60", "5");

		for (auto i : k)
			cout << i << " ";
		cout << endl;

	}
	{
		auto k = longDiv("219", "11");

		for (auto i : k)
			cout << i << " ";
		cout << endl;

	}
	{
		auto k = longDiv("729", "9");

		for (auto i : k)
			cout << i << " ";
		cout << endl;

	}
	{
		auto k = longDiv("600001", "100");

		for (auto i : k)
			cout << i << " ";
		cout << endl;

	}

   

	
}