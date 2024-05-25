#include <bits/stdc++.h>
using namespace std;


#define all(v)        ((v).begin()), ((v).end())
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define pb            push_back
#define ppb           pop_back
#define sz(x)         ((int)(x).size())
#define F             first
#define S             second
#define B             begin()
#define E             end()
#define clr(x)        memset(x,0,sizeof(x))


typedef long long ll;
typedef unsigned long long ull;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<bool>      vb;
typedef vector<vb>        vvb;
typedef vector<string>    vs;
typedef vector<int>       vi;
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

const int N = 3e5, M = 10;
int k,n,m;


void solve(){
    cin>>n; string s; cin>>s;
    int Ns=0, Ss=0,Es=0, Ws= 0;
    for(char c: s){
        switch (c)
        {
        case 'N':
            Ns++;
            break;
        case 'S':
            Ss++;
            break;
        case 'E':
            Es++;
            break;
        case 'W':
            Ws++;
            break;
        default:
            break;
        }
    }
    int y = Ns- Ss, x = Es -Ws;
    vi R(4);
    if(y%2==0 && x%2 ==0 && !(Ns==1 && Ss==1 && !Es && !Ws|| Es==1 && Ws==1 && !Ns && !Ss)){
        y/=2; x/=2;
        if(y>0) R[0] += y;
        else if(y<0) R[2] += -y;
        else if(y==0 && Ns>0) R[0]=1, R[2]=1;

        if(x>0) R[1] += x;
        else if (x<0) R[3]+= -x;
        else if(x==0 && Es> 0 && R[0]==0 && R[2]==0) R[1]=1, R[3]=1;
    }
    else{
        cout<<"NO"<<endl;
        return;
    }
    for(char c: s){
        int i = (c=='N'?0: (c=='E'? 1: (c=='S'? 2: 3)) );
        if(R[i]>0) {
            R[i]--;
            cout<<'R';
        } else  cout<<'H';
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    while(t--) solve();
    

    return 0;
}