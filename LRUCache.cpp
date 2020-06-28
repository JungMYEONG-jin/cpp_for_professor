#include <cassert>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>


using namespace std;



struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val)
		:prev(p), next(n), key(k), value(val)
	{};

	Node(int k, int val)
		:prev(NULL), next(NULL), key(k), value(val)
	{};
};


class Cache {

protected:
	map<int, Node*> mp;
	int cp=0;
	Node* tail=nullptr; //tail pointer double linked list
	Node* head=nullptr;
	virtual void set(int, int) = 0;
	virtual int get(int) = 0; //map에 key값 find해서 값 return 


};

class LRUCache : public Cache
{
public:
	LRUCache(int capacity)
	{
		
		this->cp = capacity;
		head = new Node(0, 0);
		tail = new Node(0, 0);
		head->next = tail;
		tail->prev = head;

	}


	void insertToHead(Node* node)
	{
		this->head->next->prev = node;
		node->next = this->head->next;
		node->prev = this->head;
		this->head->next = node;
		mp[node->key] = node;
	}

	void removeNode(Node* node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		
		mp.erase(node->key);
	}



	int get(int key)
	{
		if (mp.find(key) == mp.end())
			return -1;
		Node* pnode = mp[key];
		removeNode(pnode);
		insertToHead(pnode);
		return pnode->value;
	}

	void set(int key, int value)
	{
		Node* pnode =new Node(key, value);
		if (mp.find(key) != mp.end())
		{
			Node* old = mp[key];
			removeNode(old);
		}
		else {
			if (mp.size() >= cp)
			{
				Node* tailnode = tail->prev;
				removeNode(tailnode);
			}
		}
		insertToHead(pnode);
	}




};


int main()
{
	int n, capacity, i;
	cin >> n >> capacity;
	LRUCache l(capacity);
	for (int i = 0; i < n; i++)
	{
		string command;
		cin >> command;
		if (command == "get")
		{

			int key;
			cin >> key;
			//cout << get(key) << endl;


		}
		else if (command == "set")
		{
			int key, val;
			cin >> key >> val;
			l.set(key, value);

		}

	}

	return 0;
}
