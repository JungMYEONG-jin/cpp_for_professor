
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops


struct Workshop
{
    int istart;
    int idur;
    int iend;
};



struct Available_Workshops
{
    int count;
    vector<Workshop> work;

};


Available_Workshops* initialize(int* start_time, int* duration, int n)
{
    Available_Workshops* ptr = new Available_Workshops;
    ptr->count = n;
    for (int i = 0; i < n; i++)
    {

        Workshop a;
        a.istart = start_time[i];
        a.idur = duration[i];
        a.iend = start_time[i] + duration[i];

        ptr->work.push_back(a);
        
    }

    return ptr;
}
        

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int cnt = 0;

    sort(ptr->work.begin(), ptr->work.end(), [](Workshop A, Workshop B) {return A.iend < B.iend; });

    int current_end = 0;
    for (int i = 0; i < ptr->count; i++)
    {
        if (ptr->work[i].istart >= current_end)
        {
            cnt++;
            current_end = ptr->work[i].iend;
        }




    }
    


    return cnt;

}
