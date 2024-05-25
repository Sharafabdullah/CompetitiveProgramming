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

    char arr[30] = {
        'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
        'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
        'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'};
    string key[3] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
    string m = "";

    char s;
    cin >> s;
    string c;
    cin >> c;

    if (s == 'L')
    {
        for (int i = 0; i < c.length(); i++)
        {
            // auto pos = find(arr, arr + 3, c[i]);

            int pos = key[0].find(c[i]);
            if (pos != -1)
            {
                m += key[0][pos + 1];
            }
            if (pos == -1)
            {
                pos = key[1].find(c[i]);
                m += key[1][pos + 1];
            }
            if (pos == -1)
            {
                pos = key[2].find(c[i]);
                m += key[2][pos + 1];
            }

            // m += pos;
        }
    }
    if (s == 'R')
    {
        for (int i = 0; i < c.length(); i++)
        {
            // auto pos = find(arr, arr + 30, c[i]);
            // --pos;
            // m += (*pos);

            int pos = key[0].find(c[i]);
            if (pos != -1)
            {
                m += key[0][pos - 1];
            }
            if (pos == -1)
            {
                pos = key[1].find(c[i]);
                m += key[1][pos - 1];
            }
            if (pos == -1)
            {
                pos = key[2].find(c[i]);
                m += key[2][pos - 1];
            }
        }
    }
    cout << m;
    return 0;
}