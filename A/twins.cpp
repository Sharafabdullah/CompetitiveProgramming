#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <algorithm>
#include <utility>
#include <iterator>

#include <sstream>

using namespace std;

int main()
{
    // cout << 'h';
    vector<int> v;
    int sum = 0, c, n, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
        sum += c;
    }
    sort(v.begin(), v.end());
    // for (int i : v)
    //     cout << i << "    ";
    c = 0;
    while (c <= sum - c)
    {
        c += *(v.end() - 1);
        num++;
        v.pop_back();
    }
    cout << num;
    return 0;
}