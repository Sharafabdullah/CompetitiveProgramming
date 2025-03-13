#include <bits/stdc++.h>
using namespace std;

#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))
#define endl          '\n'
#define coutfloat(n,d)     cout << fixed << setprecision(d) << n << endl
#define FASTIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
typedef vector<ll>       vll;
typedef vector<double>    vd;
typedef vector< vi >      vvi;

#ifndef ONLINE_JUDGE
#define deb(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define deb(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 1e6+10;
int k, n, m;

#include <deque>
#include <vector>

using namespace std;

constexpr int base = 31;

struct Hashing {
public:
    // using HashType = int;

private:
    int len, h;
    deque<char> d;
    vector<int> pw; 
    int invVal;     

    int add(int a, int b) {
        return (a + b) % mod;
    }

    int sub(int a, int b) {
        return (a - b + mod) % mod;
    }

    int mul(int a, int b) {
        return (1LL * a * b) % mod;
    }

    int modInverse(int x) {
        // Fermat's little theorem: x^(mod-2) is the modular inverse of x mod `mod`
        int res = 1, exp = mod - 2;
        while (exp) {
            if (exp % 2) res = mul(res, x);
            x = mul(x, x);
            exp /= 2;
        }
        return res;
    }

public:
    Hashing() : len(0), h(0), invVal(modInverse(base)) {
        pw.push_back(1); 
    }

    void push_back(char c) {
        int dig = c - 'a' + 1;
        h = add(h, mul(dig, pw[len]));
        d.push_back(c);
        len++;
        if (len >= pw.size()) {
            pw.push_back(mul(pw.back(), base));
        }
    }

    void pop_back() {
        if (len == 0) return;
        int dig = d.back() - 'a' + 1;
        len--;
        h = sub(h, mul(dig, pw[len]));
        d.pop_back();
    }

    void push_front(char c) {
        int dig = c - 'a' + 1;
        h = add(mul(h, base), dig);
        d.push_front(c);
        len++;
    }

    void pop_front() {
        if (len == 0) return;
        int dig = d.front() - 'a' + 1;
        h = sub(h, dig);
        h = mul(h, invVal);
        d.pop_front();
        len--;
    }

    int get() const {
        return h;
    }

    void clear() {
        d.clear();
        len = 0;
        h = 0;
    }
};


void solve(){
    string s, t; cin >> s >> t;
    if(t.size() > s.size()){
        cout << "Not Found!" << endl<<endl;
        return;
    }

    Hashing txt, pat;
    rep(i, 0, t.size()){
        txt.push_back(s[i]);
        pat.push_back(t[i]);
    }

    vi ans;
    if(txt.get() == pat.get()){
        ans.pb(1);
    }

    for(int i = t.size(); i < s.size(); i++){
        txt.push_back(s[i]);
        txt.pop_front();
        deb(txt.get());
        deb(pat.get());
        if(txt.get() == pat.get()){
            ans.pb(i + 2 - t.size());
        }
    }

    if(ans.empty()){
        cout << "Not Found!" << endl;
    } else {
        cout << ans.size() << endl;
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
    cout<<endl;
}

int main(){
    FASTIO;
    // init();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
