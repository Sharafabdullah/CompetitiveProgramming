#include <set>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <utility>
#include <iterator>

#include <sstream>

#include <iostream>
using namespace std;

int main()
{

    vector<int> v;
    int n, row, shoot;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> row;
        v.push_back(row);
    }
    int r;
    cin >> r;
    for (size_t i = 0; i < r; i++)
    {
        cin >> row >> shoot;
        row--;
        shoot--;
        if (row - 1 >= 0)
            v[row - 1] += (shoot);
        if (row < v.size())
            v[row + 1] += (v[row] - shoot - 1);
        v[row] = 0;
        // for_each(v.begin(), v.end(), [](int x){cout<<x<<"   ";});
        // cout<<endl;
    }
    for_each(v.begin(), v.end(), [](int x)
             { cout << x << endl; });

    return 0;
}