#include <iostream>
using namespace std;

int main()
{

    int n, h;
    cin >> n >> h;
    int totW=0, curH;
    for (size_t i = 0; i < n; i++)
    {
        cin >> curH;
        if (curH > h)
        {
            totW += 2;
        }
        else
        {
            totW++;
        }
    }
    cout << totW;

    return 0;
}