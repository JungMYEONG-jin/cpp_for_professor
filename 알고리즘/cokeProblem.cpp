#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a){
        int bottle = (n/a) * b;
        int minus = (n/a) * a;
        n = n - minus + bottle;
        answer+=bottle;
    }
    return answer;
}
