#ifndef SCORE_SORTER_H_INCLUDED
#define SCORE_SORTER_H_INCLUDED

//sorts scores by quicksort
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
class score_sorter
{
    public:
    int quick_sort_partition(vector<pair<string,int>> &score_set,int l,int h)
    {
        pair <string,int> piv=score_set[h];
        int i=l-1;
        for (int j=l;j<=h-1;j++)
    {
        if (score_set[j].second<piv.second)
        {
            i++;
            swap(score_set[i],score_set[j]);
        }
    }
    swap(score_set[i+1],score_set[h]);
    return (i+1);
    }
    void quick_sort(vector<pair<string,int>> &score_set,int l,int h)
    {
        if(l<h)
        {
            int p=quick_sort_partition(score_set,l,h);
            quick_sort(score_set,l,p-1);
            quick_sort(score_set,p+1,h);
        }
    }
};
#endif // SCORE_SORTER_H_INCLUDED
