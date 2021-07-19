#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;


struct Node
{
    Node *prev;
    Node *next;
    int val;
    
    Node(int val)
    {
        this->val = val;
        prev=NULL;
        next=NULL;
    }
};



struct LinkedList
{
    Node* head;
    Node* tail;
    LinkedList() : head(NULL), tail(NULL) {}
    
    
    Node* erase(Node* node)
    {
        if(node==head)
        {
            head = node->next;
            node->next->prev=NULL;
            return node->next;
        }
        else if(node==tail)
        {
            tail = node->prev;
            node->prev->next = NULL;
            return node->prev;
        }else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            return node->next;
        }
    }
    
    void insert(int val)
    {
        if(head==NULL)
        {
            Node* node = new Node(val);
            head = node;
            tail = node;
        }else
        {
            Node* node = new Node(val);
            node->prev = tail;
            tail->next = node;
            tail = tail->next;
        }
    }
    
    void rollback(Node* node)
    {
        if(node->prev==NULL)
        {
            head = node;
            node->next->prev = node;
        }else if(node->next==NULL)
        {
            tail = node;
            node->prev->next = node;
        }else
        {
            node->prev->next = node;
            node->next->prev = node;
        }
    }
    
};

stack<Node*> st;
LinkedList* List;

void init(int n)
{
    //cout<<"HEllo"<<endl;
    List = new LinkedList();
    for(int i=0;i<n;i++)
        List->insert(i);
}



string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    init(n);
    //cout<<"HEllo"<<endl;
    Node* iter = List->head;
    for(int i=0;i<k;i++)
        iter = iter->next;
    int num = 0;
    //cout<<"HEllo"<<endl;
    for(auto& i : cmd)
    {
        char ch = i[0];
        switch(ch)
        {
            case 'U':
                num = stoi(i.substr(2));
                for(int j=0;j<num;j++)
                    iter=iter->prev;
                break;
            case 'D':
                num = stoi(i.substr(2));
                for(int j=0;j<num;j++)
                    iter= iter->next;
                break;
            case 'C':
                st.push(iter);
                iter = List->erase(iter);
                break;
            case 'Z':
                Node* z = st.top();
                st.pop();
                List->rollback(z);
                break;
        }
    }
    //cout<<"HEllo"<<endl;
    string res = string(n, 'O');
    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();
        
        int idx = temp->val;
        res[idx]='X';
    }
    answer = res;
    return answer;
}
