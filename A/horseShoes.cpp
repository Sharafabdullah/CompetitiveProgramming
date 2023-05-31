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
    set<int> s;
    int x, arr[4];
    for (size_t i = 0; i < 4; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    cout << (4 - s.size());

    return 0;
}