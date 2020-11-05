#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int field2[10][10];


int checkvsl(int xx, int yy)
{
    field2[xx][yy] = 2;
    if (field2[xx - 1][yy + 1] == 1)
        return 5;
    if (field2[xx + 1][yy + 1] == 1)
        return 5;
    if ((field2[xx + 1][yy] == 1) && (field2[xx][yy + 1] == 1))
        return 5;
    if (field2[xx + 1][yy] == 1)
        return 1 + checkvsl(xx + 1, yy);
    else
    {
        if (field2[xx][yy + 1] == 1)
            return 1 + checkvsl(xx, yy + 1);
    }

    return 1;
}


bool validate_battlefield(vector<vector<int>> field)
{
    int battleship = 0;
    int cruisers = 0;
    int destroyers = 0;
    int submarines = 0;

    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
            field2[x][y] = field[x][y];


    for (int y = 0; y < 10; y++)
        for (int x = 0; x < 10; x++)
        {
            if (field2[x][y] == 1)
                switch (checkvsl(x, y))
                {
                    case 1:
                        submarines++;
                        break;
                    case 2:
                        destroyers++;
                        break;
                    case 3:
                        cruisers++;
                        break;
                    case 4:
                        battleship++;
                        break;
                    default:
                        return false;
                }
        }
    if (submarines != 4)
        return false;
    if (destroyers != 3)
        return false;
    if (cruisers != 2)
        return false;
    if (battleship != 1)
        return false;


    return true;
}
