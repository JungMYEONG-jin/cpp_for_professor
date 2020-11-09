/* BEST CODE

#include <iostream>
#include <string>

bool path_finder(std::string& maze, int n, int row, int col){
  if(row == n-1 && col == n-1)
    return true;
  else if(row < 0 || col < 0 || row >= n || col >= n || maze[row*(n+1)+col]=='W')
    return false;
  else{
    maze[row*(n+1)+col] = 'W';
    return path_finder(maze, n, row-1, col) || path_finder(maze, n, row, col-1)
        || path_finder(maze, n, row+1, col) || path_finder(maze, n, row, col+1);
  }
}

bool path_finder(const std::string& maze) {
  std::string record{maze};
  return path_finder(record, maze.find('\n'), 0, 0);
}


*/

#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;


bool path_finder(string maze) {
  // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
  // starting from (0, 0) in a n × n maze (represented as a string)
  // and return a boolean value accordingly

  stringstream sstr(maze);
  string res;
  //vector<vector<int>> temp;
  vector<vector<char>> test;
  
  while (getline(sstr, res, '\n'))
  {
    //vector<int> path2;
    vector<char> test2;
    for (auto i : res)
    {
      /*
      if (i == '.')
        path2.push_back(1);
      else
      {
        path2.push_back(0);
      }
      */
      test2.push_back(i);
    }
    //temp.push_back(path2);
    test.push_back(test2);
  }

  int max_len = test[0].size() - 1;
  deque<vector<int>> stack;

  stack.push_back({ 0,0 });
  while (!stack.empty())
  {
    auto ele = stack.back();
    stack.pop_back();

    int x = ele[1];
    int y = ele[0];

    if (ele == vector<int> {max_len, max_len})
      return true;

    if (test[y][x] == 'p')
      continue;


  // check the direction
    if (max_len >= y && max_len >= x + 1 && test[y][x + 1] == '.' && test[y][x + 1] != 'p')
      stack.push_front({ y,x + 1 });
    if (max_len >= y + 1 && max_len >= x && test[y + 1][x] == '.' && test[y + 1][x] != 'p')
      stack.push_front({ y + 1, x });
    if (y - 1 >= 0 && x >= 0 && test[y - 1][x] == '.' && test[y - 1][x] != 'p')
      stack.push_front({ y - 1, x });
    if (y  >= 0 && x-1 >= 0 && test[y][x-1] == '.' && test[y][x-1] != 'p')
      stack.push_front({ y, x-1});

    test[y][x] = 'p';

  }




  return false;


}


// 이 풀이도 가능
/*

#include <iostream>
#include <string>

using namespace std;


bool isSafe(vector<vector<int>>& maze, int x, int y)
{
  if (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1)
    return true;
  return false;
}




bool maze_util(vector<vector<int>>& maze, int x, int y);

bool path_finder(string maze) {
  // TODO: Determine whether one can reach the exit at (n - 1, n - 1)
  // starting from (0, 0) in a n × n maze (represented as a string)
  // and return a boolean value accordingly

  stringstream sstr(maze);
  string res;
  vector<vector<int>> temp;
  vector<vector<char>> test;
  
  while (getline(sstr, res, '\n'))
  {
    vector<int> path2;
    vector<char> test2;
    for (auto i : res)
    {
      
      if (i == '.')
        path2.push_back(1);
      else
      {
        path2.push_back(0);
      }
      
      test2.push_back(i);
    }
    temp.push_back(path2);
    test.push_back(test2);
  }

  vector<vector<int>> sol(temp.size(), vector<int>(temp.size(), 0));


  if (maze_util(temp, 0, 0) == true)
    return true;
  return false;



  
}

bool maze_util(vector<vector<int>>& maze, int x, int y)
{
  int N = maze.size();
  if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
  {
    maze[x][y] = 1;
    return true;
  }

  //check maze is valid
  if (isSafe(maze, x, y) == true)
  {
    maze[x][y] = 0;
    // move forward
    if (maze_util(maze, x - 1, y) == true)
      return true;

    // if forward failed then down move
    if (maze_util(maze, x, y + 1) == true)
      return true;
    if (maze_util(maze, x +1, y) == true)
      return true;
    if (maze_util(maze, x, y - 1) == true)
      return true;

    // if both failed 
    return false;
  }
  return false;

}

*/
