#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <utility>
#include <iterator>
#include <string>

#include <sstream>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << (s1 == s2);
    // if(s1.length()!=s2.length()) {cout<< max(s1.length(), s2.length());
    // }
    // else{
    //     if(s1==s2) cout<< -1;
    //     else{
    //         cout<<s1.length();

    //     }
    // }
    if (s1 == s2)
        cout << -1;
    else
    {
        cout << max(s1.length(), s2.length());
    }

    return 0;
}