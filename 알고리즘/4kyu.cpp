#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;



string get_longest(string input)
{
    int N = input.size();
    if (N == 0)
        return "";
    N = 2 * N + 1; //Position count 
    vector<int> L(N); //LPS Length Array 
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;

    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 1; i < N; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror = 2 * C - i;
        L[i] = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R 
        if (diff > 0)
            L[i] = min(L[iMirror], diff);

        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while (((i + L[i]) < N && (i - L[i]) > 0) &&
            (((i + L[i] + 1) % 2 == 0) ||
                (input[(i + L[i] + 1) / 2] == input[(i - L[i] - 1) / 2])))
        {
            L[i]++;
        }

        if (L[i] > maxLPSLength)  // Track maxLPSLength 
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    }
    //printf("\n"); 
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
    return input.substr(start, end + 1);

}



string palindrome(string s, unsigned long i, unsigned long j) {
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        i--;
        j++;
    }
    return s.substr(i + 1, j - 1 - i);
}


string longest_palindrome2(string input) {
    string maxp = "";
    for (int i = 0; i < input.length(); i++) {
        string s1 = palindrome(input, i, i);
        string s2 = palindrome(input, i, i + 1);
        maxp = maxp.length() < s1.length() ? s1 : maxp;
        maxp = maxp.length() < s2.length() ? s2 : maxp;
    }
    return maxp;
}







string get_longest_test(string input)
{
    int window_size = input.size();

    if (window_size <= 1)
        return input;


    while (window_size > 0)
    {
        int offset = 0;
        while (offset + window_size <= input.size()) {
            string window = input.substr(offset, window_size);
            string left = window.substr(0, window_size / 2);
            reverse(left.begin(), left.end());
            string right = "";
            if (window_size % 2)
                right = window.substr(window_size - window_size / 2);
            else
                right = window.substr(window_size / 2);
            if (left == right)
                return window;

            offset += 1;

        }
        window_size -= 1;
    }

    return "";
}


