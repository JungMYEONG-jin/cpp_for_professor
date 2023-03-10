using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long tk = d;
    for (long i = 0; i <= d; i += k) {
        double y = sqrt(tk * tk - i * i);
        answer += floor(y/k) + 1;
    }
    return answer;
}
