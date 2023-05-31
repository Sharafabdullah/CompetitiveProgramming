#include <iostream>
using namespace std;
int main()
{

    int x, y, z, w, imp = 0;
    cin >> w;
    for (size_t i = 0; i < w; i++)
    {
        cin >> x >> y >> z;
        if ((x + y + z) >= 2)
        {
            imp++;
        }
    };
    cout << imp;

    return 0;
}