```c++
vector<int> partitionLabels(string s) {
    int idx[26];
    int len = s.size();
    for(int i=0;i<len;i++){
        idx[s[i] -'a'] = i; // alphabet의 가장 마지막 등장 index를 저장하자.
    }

    vector<int> result;
    int pos = 0;
    int last = 0;
    for(int i=0;i<len;i++){
        last = max(last, idx[s[i] - 'a']);
        if(i == last){
            result.push_back(last - pos + 1);
            pos = i+1;
        }
    }
    return result;
}
```
