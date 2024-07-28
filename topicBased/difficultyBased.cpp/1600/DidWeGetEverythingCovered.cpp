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



const ll inf = 1e9+1000;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

const int N = 26, M = 10;
int k,n,m;


void solve(){
    string s; 
    cin>>n>>k>>m>>s;
    vi freq(N);
    vvi ans(N, vi(N));
    rep(i,0,m){
        rep(j,0,k){
            if(freq[j]>=n-1){
                ans[s[i]-'a'][j]=1;
            }
        }
        freq[s[i]-'a']++;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(ans[i][j]==0) {
                cout<<"NO"<<endl;
                for (int l = 0; l < n-1; l++)
                {
                    cout<<char(j+'a');
                }
                cout<<char(i+'a')<<endl;
                return;
            }
        }
        
    }
    cout<<"YES"<<endl;
    
}

void solve2(){
    string s;
    cin>>n>>k>>m>>s;
    string ex = "";
    int counter=  0;
    vb found(N);
    for(char ch: s){
        if(ex.size()==n){
            break;
        }
        counter += (!found[(ch-'a')]);
        found[ch-'a']=1;
        if(counter==k){
            ex+= ch;
            found.assign(N,0);
            counter= 0;
        }
    }
    if(ex.size()==n){
        cout<<"YES"<<endl;
    }
    else{
        rep(i,0,k){
            if(!found[i]){
                while(ex.size()<n)
                    ex+=(char)('a'+i);

            }
        }
        cout<<"NO"<<endl;
        cout<<ex<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    

    return 0;
}