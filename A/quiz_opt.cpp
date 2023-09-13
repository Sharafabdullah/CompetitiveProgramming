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

    long long c = 0, s = 0, n, m, k, sp;
    cin >> n >> m >> k;
    sp = n - m;
    vector<int> v(n, 0);
    // for (int i : v)
    // {
    //     cout << i << "  ";
    // }
    // cout << endl;
    for (long long i = (n - 1); i >= 0; i--)
    {
        if (sp <= 0)
        {
            v[i] = 1;
        }
        else if (c < (k - 1))
        {
            v[i] = 1;
            c++;
            // cout << "c is " << c << endl;
        }
        else if (c == (k - 1))
        {
            c = 0;
            v[i] = 0;
            sp--;
            // cout << "sp after mod: " << sp << endl;
        }
        // v[i] = 1;
    }
    // for (int i : v)
    //     cout << i << " ";
    c = 0;
    s = 0;
    for (int i : v)
    {
        if (i)
        {
            s = (i + s) % (1000000009);
            c++;
            if (c == k)
            {
                s = (s * 2) % (1000000009);
                c = 0;
            }
        }
        else
        {
            c = 0;
        }
    }
    cout << s;
    return 0;
}