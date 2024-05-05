#include <bits/stdc++.h>
using namespace std;

#define P(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cerr << *it << " = " << a << endl;
err(++it, args...);}

#define all(v)        ((v).begin()), ((v).end())
//can go back and forwards - almost all types
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//#define pb            push_back
#define mp            make_pair
#define B             begin()
#define E             end()


typedef long long ll;
typedef long double   ld;
typedef pair<int, int> pi;
typedef vector<int>       vi;
typedef vector<double>    vd;
typedef vector< vi >      vvi;
const ll inf = 1e9;
const double eps = (1e-8);
const ll mod = 1e9 + 7;

ll d,n;
ll sum;
vi a;
void bt(int i, ll cur){
    if(i==n){
        if( cur <= sum-cur) d = min(d,abs( (sum-2*cur)) );
        return;
    }
    bt(i+1, cur+a[i]);
    bt(i+1,cur);
}
using namespace chrono; steady_clock::time_point tstt,endt;
void start(){tstt = steady_clock::now();}
void end(int i = 0){
    if(!i) cout<<"Time: "<<duration_cast<microseconds>(steady_clock::now()- tstt).count()<<char(230)<<"s"<<endl;
    else cout<<"Time: "<<duration_cast<milliseconds>(steady_clock::now()- tstt).count()<<"ms"<<endl;}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    for (int i = 1; i <= 10; ++i) {
        std::string inputFileName ="./testsApple/"+  std::to_string(i) + ".in";
        std::string outputFileName ="./testsApple/"+ std::to_string(i) + ".out";

        std::ifstream inputFile(inputFileName);
        std::ifstream outputFile(outputFileName);

        if (!inputFile.is_open() || !outputFile.is_open()) {
            std::cerr << "Error opening files " << inputFileName << " or " << outputFileName << std::endl;
            break;
        }

        // Read input from input file
        d=inf;
        sum = 0;
        a = vi(n); rep(i,0,n) {cin>>a[i];sum+=a[i];}
        bt(0,0);
        cout<<d<<endl;

        // Read expected output from output file
        std::string expectedOutputContent;
        std::getline(outputFile, expectedOutputContent);
        P(expectedOutputContent);

        // Close files
        inputFile.close();
        outputFile.close();

        // Compare input content with expected output content
        if (d ==stoi(expectedOutputContent) ) {
            std::cout << "File " << inputFileName << " matches " << outputFileName << std::endl;
        } else {
            std::cout << "File " << inputFileName << " does not match " << outputFileName << std::endl;
        }
    }
    
    

    


    return 0;
}