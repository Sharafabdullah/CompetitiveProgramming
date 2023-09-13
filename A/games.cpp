#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int t1, t2, n, cnt = 0;
    vector<pair<int, int>> v;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        v.push_back(make_pair(t1, t2));
    }
    // for (size_t i = 0; i < n; i++)
    // {
    //     cout << v[i].first << " " << v[i].second;
    //     cout << endl;
    // }

    

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (v[i].second == v[j].first && i != j)
                cnt++;
        }
    }
    cout << cnt;

    return 0;
}