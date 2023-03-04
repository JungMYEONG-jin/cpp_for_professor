// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(tree * T) {
    // Implement your solution here
    if(T == NULL)
        return -1;
    int left = solution(T->l) + 1;
    int right = solution(T->r) + 1;
    return max(left, right);
}
