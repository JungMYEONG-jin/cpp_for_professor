#include <string>
#include <vector>

using namespace std;
// 조건이 한정적이라 backtracking으로 가능할듯?

int maxService = 0;
int maxPrice = 0;
int temp[4] = {10, 20, 30, 40};

void calc(vector<int>& rates, vector<vector<int>>& users, vector<int>& emoticons){
    int service = 0;
    int price = 0;
    
    for(auto user : users){
        int val = 0;
        for(int i=0, len = rates.size(); i < len; i++){
            if(user[0] > rates[i])
                continue;
            val += (emoticons[i] / 100) * (100 - rates[i]);
        }
        // 금액이 최대치보다 크면 서비스 증가
        if(val >= user[1])
            service++;
        else
            price += val;  
    }
    
    if(maxService > service)
        return;
    
    if(maxService == service && maxPrice > price)
        return;
    maxService = service;
    maxPrice = price;
}


void dfs(vector<int> rates, vector<vector<int>>& users, vector<int>& emoticons)
{
    if(rates.size() == emoticons.size()){
        calc(rates, users, emoticons);
        return;
    }
    
    for(int i=0;i<4;i++){
        rates.push_back(temp[i]);
        dfs(rates, users, emoticons);
        rates.pop_back();
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    vector<int> rates;
    dfs(rates, users, emoticons);
    
    answer.push_back(maxService);
    answer.push_back(maxPrice);
    return answer;
}
