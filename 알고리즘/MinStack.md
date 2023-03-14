```c++
class MinStack {
public:
    MinStack() {
        
    }

    vector<pair<int, int>> result;
    
    void push(int val) {
        if(result.empty())
            result.push_back({val, val});
        else{
            result.push_back({val, min(val, result.back().second)});
        }
    }
    
    void pop() {
        if(!result.empty())
            result.pop_back();
    }
    
    int top() {
        return result.back().first;
    }
    
    int getMin() {
        return result.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
