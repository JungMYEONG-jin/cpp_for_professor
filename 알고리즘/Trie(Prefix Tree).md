```c++
class Trie {
    struct TrieNode{
        char val;
        int count;
        bool isEnd;
        TrieNode* children[26];
    };
    TrieNode* root;

    TrieNode* getNode(int idx){
        TrieNode* node = new TrieNode();
        node->val = 'a'+idx;
        node->count = 0;
        node->isEnd = false;
        for(int i=0;i<26;i++)
            node->children[i] = NULL;
        return node;
    }

public:
    Trie() {
        root = getNode('/' - 'a');
    }
 
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0 ; i<word.size();i++){
            int idx = word[i] - 'a';
            if(!temp->children[idx])
                temp->children[idx] = getNode(idx);
            temp->children[idx]->count++;
            temp = temp->children[idx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0 ; i<word.size();i++){
            int idx = word[i] - 'a';
            if(!temp->children[idx])
                return false;

            temp = temp->children[idx];
        }
        return (temp->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        int idx = 0;
        for(int i=0 ; i<prefix.size();i++){
            int idx = prefix[i] - 'a';
            if(temp->children[idx] == NULL)
                return false;

            temp = temp->children[idx];
        }
        return temp->count > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
