#include <cmath>
#include <iostream>
using namespace std;

int main()
{

    int n, t, k, d;
    cin >> n >> t >> k >> d;
    // cout<<t * ceil(n / (double)k)<<endl;
    // cout<< t * ceil((n / (double)(2 * k))) +d<<endl;
    // cout << (t * (int)ceil(n / k) <= t * (int)ceil((n / (2 * k))) + d ? "NO" : "YES");

    //didn't understand the question well earlier
    int o1=0, o2=d;
    for (size_t i = 0; i < ((n+k-1)/k); i++)
    {
        if (o1<=o2) o1+=t;
        else o2+=t;
    }
    cout<<(t*((n+k-1)/k)<= max(o1,o2)? "NO": "YES");
    

    return 0;
}