#include <vector>
using namespace std;
std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, size_t n){
  // TODO: Return the result of A × B in the form of an n × n matrix
  // NOTE: Please allocate and return matrix C
  vector<vector<int>> res(n, vector<int>(n));
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      for(int k=0;k<n;k++)
        res[i][j] += a[i][k]*b[k][j];
    }
  }
  
  return res;
  
}

// 미리 메모리 할당해주면 재할당을 안해서 성능이 빨라짐
