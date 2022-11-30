#include <vector>

using namespace std;

int countInversions(const std::vector<int>& vec) {

    vector<int> res = vec;

    int count = 0;

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.size() - 1 - i; j++)
        {
            if (res[j] > res[j + 1])
            {
                std::swap(res[j], res[j + 1]);
                count++;
            }
        }
    }

    return count;

}