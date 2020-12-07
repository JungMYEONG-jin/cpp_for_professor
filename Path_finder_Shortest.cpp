#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <queue>

using namespace std;

int path_finder(string maze) {
  // TODO: Return the minimal number of steps required to reach the exit located at
  // (n - 1, n - 1) from the initial position (0, 0) in an n × n maze if possible and
  // -1 otherwise
  
int len = sqrt(maze.size());

        if (len == 1) // (0,0)
            return 0;

        set<int> visit;
        visit.insert(0);
        queue<pair<int, int>> res;
        res.push({ 0,0 });

        while (!res.empty())
        {
            auto i = res.front();
            int cur = i.first;
            int step = i.second;
            res.pop();
            int north = cur - len - 1;
            int south = cur +len + 1;
            int west = cur - 1;
            int east = cur + 1;

            int dir[] = { north, south, west, east };

            for (int j = 0; j < 4; j++)
            {
                if (dir[j] < 0)
                    continue;
                if (dir[j] >= maze.size())
                    continue;
                if (visit.count(dir[j]))
                    continue;
                if (maze[dir[j]] != '.')
                    continue;

                visit.insert(dir[j]);
                res.push({ dir[j], step + 1 });

                if (dir[j] == maze.size() - 1)
                    return step + 1;
            }


        }
        return -1;
}
