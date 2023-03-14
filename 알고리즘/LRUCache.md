```c++
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    } 
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        db.erase(node->key);
    }


    void insertToHead(Node* node) {
        this->head->next->prev = node;
        node->next = this->head->next;
        node->prev = this->head;
        this->head->next = node;

        db[node->key] = node;
    }

    int get(int key) {
        if (db.find(key) == db.end())
            return -1;
        auto it = db[key];
        remove(it);
        insertToHead(it);
        return it->value;
    }

    void put(int key, int value) {
        Node* node = new Node(key, value);
        if (db.find(key)!=db.end()) {
            auto it = db[key];
            remove(it);
        }
        else {
            if (db.size() >= capacity) {
                Node* del = tail->prev;
                remove(del);
            }
        }
        insertToHead(node);
    }

private:
    int capacity;
    map<int, Node*> db;
    Node* head;
    Node* tail;
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
