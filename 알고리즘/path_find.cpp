#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>


using namespace std;


map<pair<int, int>, int> db;

struct Node
{
    pair<int, int> p;
    Node* left;
    Node* right;

    Node(pair<int, int> p) : p(p), left(NULL), right(NULL) {}

    void insert(pair<int ,int> cp)
    {
        if(p.first>cp.first)
        {
            if(left)
                left->insert(cp);
            else
                left = new Node(cp);
        }else
        {
            if(right)
                right->insert(cp);
            else
                right = new Node(cp);
        }
    }

    void preorder(vector<int>& v)
    {
        v.push_back(db[p]);
        if(left)
            left->preorder(v);
        if(right)
            right->preorder(v);
    }

    void postorder(vector<int>& v)
    {
        if(left)
            left->postorder(v);
        if(right)
            right->postorder(v);
        v.push_back(db[p]);
    }

};




vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int j = 0;
    for(auto& i : nodeinfo)
        db[{i[0], i[1]}] = ++j;


    sort(nodeinfo.begin(), nodeinfo.end(), [](auto e, auto k){return e[1]>k[1] || e[1]==k[1] && e[0]<=k[0];});

    Node* root = new Node({nodeinfo[0][0], nodeinfo[0][1]});
    for(int i=1, len = nodeinfo.size();i<len;i++)
        root->insert({nodeinfo[i][0], nodeinfo[i][1]});
    vector<int> vec1, vec2;
    root->preorder(vec1);
    root->postorder(vec2);
    answer.push_back(vec1);
    answer.push_back(vec2);
    return answer;
}
