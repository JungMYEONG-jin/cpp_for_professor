long long getDiv(long long val){
    long num = sqrt(val);
    for(long i=2;i<=num;i++){
        if (val%i ==0 && val/i<=10000000)
        {
            /* code */
            return val/i;
        }
    }    
    return 1;
}


vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for(long long i=begin;i<=end;i++){
        answer.push_back(getDiv(i));
    }
    if (begin==1)
    {
        /* code */
        answer[0] = 0;
    }
    
    return answer;
}
