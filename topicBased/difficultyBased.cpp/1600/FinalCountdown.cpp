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

const int N = 3e5, M = 10;
int k,n,m;

class BigInt {
public:
    std::vector<int> digits;
    bool isNegative;

    BigInt() : isNegative(false) {}

    BigInt(const std::string &number) {
        isNegative = number[0] == '-';
        for (int i = isNegative ? 1 : 0; i < number.size(); ++i) {
            if (isdigit(number[i])) {
                digits.push_back(number[i] - '0');
            }
        }
        std::reverse(digits.begin(), digits.end());
    }

    BigInt(const BigInt &other) : digits(other.digits), isNegative(other.isNegative) {}

    BigInt& operator=(const BigInt &other) {
        if (this == &other) return *this;
        digits = other.digits;
        isNegative = other.isNegative;
        return *this;
    }

    // Addition
    BigInt operator+(const BigInt &other) const {
        if (isNegative == other.isNegative) {
            BigInt result = addAbsoluteValues(*this, other);
            result.isNegative = isNegative;
            return result;
        }
        if (isNegative) return other - (-(*this));
        return *this - (-other);
    }

    // Subtraction
    BigInt operator-(const BigInt &other) const {
        if (isNegative == other.isNegative) {
            if (absCompare(*this, other) >= 0) {
                BigInt result = subtractAbsoluteValues(*this, other);
                result.isNegative = isNegative;
                return result;
            }
            BigInt result = subtractAbsoluteValues(other, *this);
            result.isNegative = !isNegative;
            return result;
        }
        return *this + (-other);
    }

    // Multiplication with BigInt
    BigInt operator*(const BigInt &other) const {
        BigInt result;
        result.digits.resize(digits.size() + other.digits.size(), 0);
        result.isNegative = isNegative != other.isNegative;
        
        for (size_t i = 0; i < digits.size(); ++i) {
            for (size_t j = 0; j < other.digits.size(); ++j) {
                result.digits[i + j] += digits[i] * other.digits[j];
                if (result.digits[i + j] >= 10) {
                    result.digits[i + j + 1] += result.digits[i + j] / 10;
                    result.digits[i + j] %= 10;
                }
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    // Multiplication with integer
    BigInt operator*(int num) const {
        BigInt result;
        result.digits.resize(digits.size() + 10, 0);  // 10 is a safe margin for digit carryover
        result.isNegative = isNegative != (num < 0);
        num = std::abs(num);

        int carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            long long current = result.digits[i] + (i < digits.size() ? digits[i] : 0) * 1LL * num + carry;
            result.digits[i] = current % 10;
            carry = current / 10;
        }

        result.removeLeadingZeros();
        return result;
    }

    // Negation
    BigInt operator-() const {
        BigInt result(*this);
        result.isNegative = !isNegative;
        return result;
    }

    friend std::ostream& operator<<(std::ostream &out, const BigInt &number) {
        if (number.isNegative && !number.isZero()) out << '-';
        for (auto it = number.digits.rbegin(); it != number.digits.rend(); ++it) {
            out << *it;
        }
        return out;
    }

    static BigInt addAbsoluteValues(const BigInt &a, const BigInt &b) {
        BigInt result;
        int carry = 0;
        size_t maxSize = std::max(a.digits.size(), b.digits.size());

        for (size_t i = 0; i < maxSize || carry; ++i) {
            int digitA = i < a.digits.size() ? a.digits[i] : 0;
            int digitB = i < b.digits.size() ? b.digits[i] : 0;
            int sum = digitA + digitB + carry;
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }

    static BigInt subtractAbsoluteValues(const BigInt &a, const BigInt &b) {
        BigInt result;
        int borrow = 0;

        for (size_t i = 0; i < a.digits.size(); ++i) {
            int digitA = a.digits[i];
            int digitB = i < b.digits.size() ? b.digits[i] : 0;
            int diff = digitA - digitB - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }

        result.removeLeadingZeros();
        return result;
    }

    static int absCompare(const BigInt &a, const BigInt &b) {
        if (a.digits.size() != b.digits.size()) return a.digits.size() - b.digits.size();
        for (size_t i = a.digits.size(); i-- > 0;) {
            if (a.digits[i] != b.digits[i]) return a.digits[i] - b.digits[i];
        }
        return 0;
    }

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
    }

    bool isZero() const {
        return digits.size() == 1 && digits[0] == 0;
    }
};

void solve(){
    string tmp;
    cin>>n>>tmp;
    BigInt num(tmp);
    num.removeLeadingZeros();
    reverse(all(tmp));
    // cout<<"NUM: "<<num<<endl;
    n = num.digits.size();
    BigInt dp[n+1];
    dp[0] = BigInt("0");
    rep(i,1,n){
        dp[i] = BigInt(to_string(i)) + dp[i-1]*9;
    }
    // cout<<"dp: "<<endl;
    // rep(i,0,n+1){
    //     cout<<dp[i]<<endl;
    // }
    BigInt ans("0");
    rep(i,0,n){
        ans = ans + dp[i]* BigInt(to_string(tmp[i]-'0'));
    }
    ans = ans + num;
    cout<<ans<<endl;
}

void solve2(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> a(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        a[i] = a[i + 1] + (s[i] - '0');
    }
    string res;
    int c = 0;
    for (int i = 0; i < n; i++) {
        c += a[i];
        res += (char)(c % 10 + '0');
        c /= 10;
    }
    res += (char)(c + '0');
    while (res.back() == '0') {
        res.pop_back();
    }
    reverse(all(res));
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t= 1;
    cin>>t;
    // while(t--) solve();
    while(t--) solve2();
    // cout<<to_string('9'-'0')<<endl;
    // cout<< 922 + 2*102 + 3*11 + 4*1 + 12345<<endl;

    return 0;
}