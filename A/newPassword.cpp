#include <iostream>
#include <set>
#include <random>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;
    char nChar;
    string s = "";
    set<char> Kset;
    srand(time(nullptr));
    while (s.length() < n)
    {
        nChar = rand() % 26 + 'a';
        if (nChar != s.back() && (Kset.size() < k) && Kset.count(nChar) == 0)
        {
            s += nChar;
            Kset.insert(nChar);
        }
        if (nChar != s.back() && Kset.size() == k && Kset.count(nChar) > 0)
        {
            s += nChar;
        }
    }
    cout << s;

    return 0;
}

/* 
int main(int argc, const char * argv[]) {
    
    int n, k;
    cin >> n >> k;
    
    int pos = 0;
    string res = "";
    while (n--) {
        res += 'a' + pos;
        pos = (pos + 1) % k;
    }
    cout << res << "\n";
    
    return 0;
}
 */