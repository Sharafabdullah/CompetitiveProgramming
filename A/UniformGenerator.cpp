#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;

int gcds(int s, int m)
{
    if (m == 0)
        return s;
    return gcds(m, s % m);
}
int lcm(int s, int m)
{
    int gc = gcds(s, m);
    if (gc != 0)
        return s * m / gc;
    return 0;
}
int main()
{
    int s, m;

    while (cin >> s >> m)
    {
        cout << setw(10) << right << s << setw(10) << right << m;
        if (gcds(s, m) == 1)
            cout << "    Good Choice\n\n";
        else
            cout << "    Bad Choice\n\n";
    }

    return 0;
}