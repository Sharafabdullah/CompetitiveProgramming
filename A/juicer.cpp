#include <iostream>
using namespace std;

int main()
{

    long long sum = 0, cnt = 0, cur = 0, n, b, d;
    cin >> n >> b >> d;

    for (size_t i = 0; i < n; i++)
    {
        cin >> cur;
        if (cur > b)
            continue;
        if (cur <= b)
            sum += cur;
        while (sum > d)
        {
            sum = 0;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}