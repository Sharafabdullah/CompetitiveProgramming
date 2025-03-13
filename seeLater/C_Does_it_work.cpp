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

const int N = 3e5, M = 10;
int k,n,m;


// Function to check if the board is valid
bool isValidSudoku(vector<vector<int>>& board) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
        set<int> rowSet;
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != 0) {
                if (rowSet.count(board[i][j])) {
                    cout<<"from row";
                    return false;
                    }
                rowSet.insert(board[i][j]);
            }
        }
    }
    
    // Check columns
    for (int j = 0; j < 9; ++j) {
        set<int> colSet;
        for (int i = 0; i < 9; ++i) {
            if (board[i][j] != 0) {
                if (colSet.count(board[i][j])){return false;}
                colSet.insert(board[i][j]);
            }
        }
    }
    
    for (int rowBlock = 0; rowBlock < 9; rowBlock += 3) {
        for (int colBlock = 0; colBlock < 9; colBlock += 3) {
            set<int> gridSet;
            // Iterate over the 3x3 block
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int value = board[rowBlock + i][colBlock + j];
                    if (value != 0) {
                        if (gridSet.count(value)) return false;
                        gridSet.insert(value);
                    }
                }
            }
        }
    }
    return true;
}



int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<vector<int>> board(9, vector<int>(9));
        
        // Input board
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> board[i][j];
            }
        }
        deb(board)
        
        // Check if board is valid
        if (isValidSudoku(board)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    
    return 0;
}
