    #include <bits/stdc++.h>
    using namespace std;

    #define all(v)        ((v).begin()), ((v).end())
    #define rep(i, a, b) for (int i = a; i < b; ++i)
    #define repd(i, a, b) for (int i = a; i >= b; --i)
    #define pb            push_back
    #define B             begin()
    #define E             end()
    #define clr(x)        memset(x,0,sizeof(x))
    #define endl          '\n'
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
    #define deb(...) cerr << "[" << #__VA_ARGS__ << "] = "; _print(__VA_ARGS__); cerr << endl;
    #else
    #define deb(...)
    #endif

    void _print(ll t) {cerr << t;}
    void _print(int t) {cerr << t;}
    void _print(bool t) {cerr << t;}
    void _print(string t) {cerr << t;}
    void _print(char t) {cerr << t;}
    void _print(ld t) {cerr << t;}
    void _print(double t) {cerr << t;}
    void _print(ull t) {cerr << t;}


    template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
    template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
    template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}

    template <typename T, typename... Args>
    void _print(T t, Args... args) {_print(t);cerr << ", ";_print(args...);}

    const int dx[] = {0,0,1,-1};
    const int dy[] = {1,-1,0,0};

    const ll inf = 1e16+1000;
    const double eps = (1e-8);
    const ll mod = 1e9 + 7;

    const int N = 3e5, M = 10;
    int k, n, m;
    struct Node1{
        ll pref, sum;
        Node1(){};
        Node1(ll p, ll s):pref(p), sum(s){};

    };
    template <class T> struct SegmentTree1{
        #define L (2*node + 1)
        #define R (2*node + 2)
        #define md ((l+r)/2)
    private:
        vector<T> seg;
        T skip = Node1(-inf, 0);
        int sz = 1;
        T merge(T x, T y){
            Node1 ret = Node1();
            ret.pref = max(x.pref, x.sum + y.pref);
            ret.sum = x.sum + y.sum;
            return ret;
        }
        void build(int l, int r, int node, vll& org){
            if(l==r){ 
                if(l<org.size()) seg[node]=Node1(max(org[l],0ll), org[l]);
                return;
            }

            build(l, md, L, org);
            build(md+1, r, R, org);
            seg[node] =merge(seg[L], seg[R]);
        }

        void update(int l, int r, int node, T val, int ind){
            if(l==r){
                seg[node] = val;
                return;
            }

            if(ind<=md) update(l, md, L, val, ind);
            else update(md+1, r, R, val, ind);
            
            seg[node] = merge(seg[L], seg[R]);
        }

        T query(int l, int r, int node, int lq, int rq){
            if(r<lq || l > rq) return skip;
            if(l>=lq && r<=rq) return seg[node];

            return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
        }

    public:
        SegmentTree1(vll& arr){
            while(sz<(int)arr.size()) sz*=2;
            seg = vector<T>(sz*2,skip);
            build(0, sz-1, 0, arr);
        }
        
        void update(int ind, T val){
            update(0, sz-1, 0, val, ind);
        }

        T query(int l, int r){
            return query(0, sz-1, 0, l, r);
        }
    #undef L
    #undef R
    #undef md
    };
    struct Node2{
        ll suf, sum;
        Node2(){};
        Node2(ll suf, ll s):suf(suf), sum(s){};

    };

    template <class T> struct SegmentTree2{
        #define L (2*node + 1)
        #define R (2*node + 2)
        #define md ((l+r)/2)
    private:
        vector<T> seg;
        T skip = Node2(-inf, 0);;
        int sz = 1;
        T merge(T x, T y){
            Node2 ret = Node2();
            ret.suf = max(y.suf, y.sum + x.suf);
            ret.sum = x.sum + y.sum;
            return ret;
        }
        void build(int l, int r, int node, vll& org){
            if(l==r){ 
                if(l<org.size()) seg[node]=Node2(max(org[l],0ll), org[l]);
                return;
            }

            build(l, md, L, org);
            build(md+1, r, R, org);
            seg[node] =merge(seg[L], seg[R]);
        }

        void update(int l, int r, int node, T val, int ind){
            if(l==r){
                seg[node] = val;
                return;
            }

            if(ind<=md) update(l, md, L, val, ind);
            else update(md+1, r, R, val, ind);
            
            seg[node] = merge(seg[L], seg[R]);
        }

        T query(int l, int r, int node, int lq, int rq){
            if(r<lq || l > rq) return skip;
            if(l>=lq && r<=rq) return seg[node];

            return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
        }

    public:
        SegmentTree2(vll& arr){
            while(sz<(int)arr.size()) sz*=2;
            seg = vector<T>(sz*2,skip);
            build(0, sz-1, 0, arr);
        }
        
        void update(int ind, T val){
            update(0, sz-1, 0, val, ind);
        }

        T query(int l, int r){
            return query(0, sz-1, 0, l, r);
        }
    #undef L
    #undef R
    #undef md
    };

    struct Node3{
        ll suf, sum, pref, ans;
        Node3(){};
        Node3(ll suf, ll pref, ll s, ll ans):suf(suf), sum(s), pref(pref), ans(ans){};

    };

    template <class T> struct SegmentTree3{
        #define L (2*node + 1)
        #define R (2*node + 2)
        #define md ((l+r)/2)
    private:
        vector<T> seg;
        T skip = -inf;
        int sz = 1;
        T merge(T x, T y){
            return max(x,y);
        }
        void build(int l, int r, int node, vll& org){
            if(l==r){ 
                if(l<org.size()) seg[node]=org[l];
                return;
            }

            build(l, md, L, org);
            build(md+1, r, R, org);
            seg[node] =merge(seg[L], seg[R]);
        }

        void update(int l, int r, int node, T val, int ind){
            if(l==r){
                seg[node] = val;
                return;
            }

            if(ind<=md) update(l, md, L, val, ind);
            else update(md+1, r, R, val, ind);
            
            seg[node] = merge(seg[L], seg[R]);
        }

        T query(int l, int r, int node, int lq, int rq){
            if(r<lq || l > rq) return skip;
            if(l>=lq && r<=rq) return seg[node];

            return merge(query(l, md, L, lq,rq), query(md+1, r, R, lq,rq));
        }

    public:
        SegmentTree3(vll& arr){
            while(sz<(int)arr.size()) sz*=2;
            seg = vector<T>(sz*2,skip);
            build(0, sz-1, 0, arr);
        }
        
        void update(int ind, T val){
            update(0, sz-1, 0, val, ind);
        }

        T query(int l, int r){
            return query(0, sz-1, 0, l, r);
        }
    #undef L
    #undef R
    #undef md
    };


    void solve(){
        cin>>n>>k;
        vll a(n), b(n), tmp(n); 
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) cin>>b[i];

        rep(i,0,n) tmp[i] = b[i] - a[i];

        SegmentTree1<Node1> prefSum(tmp);
        SegmentTree2<Node2> sufSum(tmp);

        vll segSum(n);
        ll cur = 0;
        rep(i,0,n){
            if(i < k-1){
                cur += b[i];
                continue;
            }
            cur+= b[i];
            if(i>=k){
                cur -= b[i-k];
            }
            segSum[i - k + 1] = cur;
        }
        deb(segSum)
        SegmentTree3<ll> maxSubarray(segSum);


        ll  ans = -inf, partSum = 0;
        cur = 0;
        rep(i,0,n){
            if(i<k-1){
                cur -= a[i];
                partSum += b[i];
                continue;
            }
            cur-=a[i];
            partSum += b[i];
            if(i>=k){
                cur+=a[i-k];
                partSum -= b[i-k];
            }
            assert(partSum == maxSubarray.query(i - k + 1, i -k + 1));
            ll p = 0, s = 0;

            ll lo = 0, hi = i - k + 1;
            auto cmp = [&](ll md){
                if(maxSubarray.query(md, i - k + 1) == partSum) return true;
                else return false;
            };
            //finds the first true given by cmp (lo). hi is the last false
            while(lo<=hi){
                ll md = lo + (hi-lo)/2;
                if(cmp(md)) hi = md - 1;
                else lo = md+1;
            }
            if(i - k  >= lo)  s = sufSum.query(lo, i - k).suf;
            deb(i, lo)

            lo = i - k + 1, hi = n - k;
            auto cmp2 = [&](ll md){
                if(maxSubarray.query(i - k + 1,md) == partSum) return true;
                else return false;
            };
            //finds the first true given by cmp (lo). hi is the last false
            while(lo<=hi){
                ll md = lo + (hi-lo)/2;
                if(!cmp2(md)) hi = md - 1;
                else lo = md+1;
            }
            lo = hi;
            deb(lo)
            lo+= k-1;
            if(i+1<= lo)  p = prefSum.query(i+1, lo).pref;
            deb(lo)


            deb(i, s , p)
            ans = max(ans, cur + max(p,0ll) + max(s, 0ll));
        }
        cout<<ans<<endl;
    }

    int main(){
        FASTIO;

        int t = 1;
        cin >> t;
        while(t--)
            solve();

        return 0;
    }
