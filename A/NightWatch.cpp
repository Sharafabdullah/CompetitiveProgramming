#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <utility>
#include <iterator>

#include <sstream>

using namespace std;

int main()
{
    // cout << "hello";

    int n, j, cnt = 0;
    cin >> n;
    vector<int> v;
    int minx = INT_MAX, maxx = INT_MIN;
    for (size_t i = 0; i < n; i++)
    {
        cin >> j;
        // if (j < min)
        //     min = j;
        // if (j > max)
        //     max = j;
        minx = min(minx, j);
        maxx = max(maxx, j);
        v.push_back(j);
    }
    // auto mm = minmax(v.begin(), v.end());
    // for (int i : v){
    //     if (i<min) min=i;
    //     if(i>max) max = i;}

    for_each(v.begin(), v.end(), [minx, maxx, &cnt](int i)
             {
        if(i> minx && i<maxx) ++cnt; });
    cout << cnt;

    return 0;
}