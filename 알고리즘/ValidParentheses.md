```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

    for(auto ch : s){
        if(ch == ')'){
            if (st.empty())
            {
                /* code */
                return false;
            }
            auto k = st.top();
            st.pop();
            if (k!='(')
            {
                return false;
            }
        }else if(ch == '}'){
            if (st.empty())
            {
                /* code */
                return false;
            }
            auto k = st.top();
            st.pop();
            if (k!='{')
            {
                return false;
            }
        }else if(ch == ']'){
            if (st.empty())
            {
                /* code */
                return false;
            }
            auto k = st.top();
            st.pop();
            if (k!='[')
            {
                return false;
            }
        }else
            st.push(ch);   
    }

        if(st.empty())
            return true;
        return false;
    }
};


```
