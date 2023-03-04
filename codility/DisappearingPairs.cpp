// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <stack>

string solution(string &S) {
    // Implement your solution here
    
    stack<char> res;
    for(int i=0, len = S.size();i<len;i++){
        if(res.empty()){
            res.push(S[i]);
        }else{
            if(res.top() == S[i])
                res.pop();
            else
                res.push(S[i]);
        }
    }

    string temp = "";
    while(!res.empty())
    {
        temp+=res.top();
        res.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
