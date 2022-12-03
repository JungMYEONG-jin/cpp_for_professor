two stack queue
merge sorted array
check is binary search tree

```c++
struct Queue {
    stack<int> s1, s2;

    void enque(int x) {
        s1.push(x);
    }

    int deque() {

        if (s1.empty() && s2.empty()) {
            exit(0);
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
};

vector<int> merge(vector<int>& left, vector<int>& right) {
    int l = 0;
    int r = 0;
    int k = 0;
    int len1 = left.size();
    int len2 = right.size();
    vector<int> arr(len1 + len2);
    while (l < len1 && r < len2) {

        if (left[l] < right[r])
            arr[k++] = left[l++];
        else
            arr[k++] = right[r++];
    }
    // 둘중 하나는 끝났을것
    while (l < len1)
        arr[k++] = left[l++];
    while (r < len2)
        arr[k++] = right[r++];
    return arr;
}

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int maxValue(struct node* node) {
    if (node == NULL)
        return INT16_MIN;
    int val = node->data;
    int left = maxValue(node->left);
    int right = maxValue(node->right);
    return max(val, max(left, right));
}

int minValue(struct node* node) {
    if (node == NULL)
        return INT16_MAX;
    int val = node->data;
    int left = minValue(node->left);
    int right = minValue(node->right);
    return min(val, min(left, right));
}

bool isBst(struct node* node) {
    if (node == NULL)
        return true;
    if (node->left != NULL && maxValue(node->left) > node->data)
        return false;
    if (node->right != NULL && minValue(node->right) < node->data)
        return false;

    if (!isBst(node->left) || !isBst(node->right))
        return false;
    return true;
}

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};


bool isBST(struct Node* root ,Node*& prev) {
    if (root) {
        if (!isBST(root->left, prev))
            return false;
        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;
        return isBST(root->right, prev);
    }
    return true;
}

bool checkBST(Node* root) {
    Node* prev = NULL;
    return isBST(root, prev);
}

```
