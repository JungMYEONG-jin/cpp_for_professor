bool isValid(int a, int b, vector<int>& g, vector<int>& s, vector<int>& w, vector<int>& t, long long times) {
    long long gold = 0;
    long long silver = 0;
    long long total = 0;

    for (int i = 0, len = g.size(); i < len; i++) {
        long long Time = t[i];
        long long Time2 = 2 * Time;
        long long move = times / Time2;
        if (times % Time2 >= Time) {
            move += 1;
        }
        long long maxWork = move * w[i];

        gold += min(static_cast<long long>(g[i]), maxWork);
        silver += min(static_cast<long long>(s[i]), maxWork);
        total += min(static_cast<long long>(g[i] + s[i]), maxWork);
    }

    if (gold >= a && silver >= b && total >= a + b)
        return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;

    long long left = 0;
    long long right = 10e14 * 4;
    answer = right;

    while (left <= right) {
        long long mid = (left + right) >> 1;
        if (isValid(a, b, g, s, w, t, mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return answer;
}
