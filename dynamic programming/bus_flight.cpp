//Rachit Garg
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(arr) arr.begin(), arr.end()
#define nl "\n"
#define cn  cout<<"\n"
#define vi  vector<int>
#define fo(i, n) for (ll i = 0; i < n; i++)
#define f1(i, n) for (ll i = 1; i <=n; i++)
#define fab(a,b) for (ll i = a; i < b; i++)
#define rfo(i, n) for (ll i = n - 1; i >= 0; i--)
#define pb push_back
#define asort(a) sort(a.begin(), a.end())
#define dsort(a) sort(a.begin(), a.end(), greater<int>())
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define MOD 1000000007
#define MOD1 998244353
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll lcm(ll  a, ll b){ return (a/__gcd(a,b))*b ; }
bool prime(int n){   if(n<0){return false;}
    for(int i =2;i*i<n;i++){
        if(n%i == 0){return false;}}
    return true;}
bool palindrome(int n){    int r,sum = 0,k;k = n;
    while(n>0){r = n%10;sum = sum * 10 + r;n = n/10;}
    if( k == sum){return true;}
    else{ return false;} }
bool isPalindrome(string S){ for (int i = 0;i <S.length() / 2; i++) {
        if (S[i] != S[S.length() - i - 1]) { return false; }}
    return true;}
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
/////////////////////////////////////  
int n,k,m;int dp[1000];vector<int> b,a;

//path jump so we can backtrack soo form 2 ending at

int rec(int i){  //min cost path from 1 to i
       if(i==0){return 0;}
       if(dp[i]!=-1)return dp[i];
       int ans= rec(i-1)+b[i-1];
       for(int j=1;i-j>=0 && j<=k;j++){
          ans=min(ans,rec(i-j)+a[i]+a[i-j]);
       }
       return dp[i]=ans;
}
//tc->O(n*k)

struct monotone_deque{
    deque<int> dq;
    void insert(int x){
       while(!dq.empty()&& dq.back()>x){dq.pop_back();}
       dq.push_back(x);
    }
    void remove(int x){
        if(!dq.empty()){
            if(dq.front()==x)dq.pop_back();
        }
    }
    int getmin(){
         if(!dq.empty()){
           return dq.front();
        }else{
            return 0;
        }
    }
};
void input(){
    cin>>n>>k>>m;b.resize(n-1);a.resize(n);
    fo(i,n-1){cin>>b[i];}
    fo(i,n){cin>>a[i];}
}
void solve(){
    input();
    dp[1]=0;
    monotone_deque dq;
    for(int i=1;i<n;i++){
        dp[i]=dp[i-1]+b[i-1];
        for(int j=1;i-j>=0 && j<=k;j++){
          dp[i]=min(dp[i],dp[i-j]+a[i]+a[i-j]);
       }
        // dq.insert(dp[i-1]+a[i-1]);
        // if(i-k-1>=0){dq.remove(dp[i-k-1]+a[i-k-1]);}
        // dp[i]=min(dp[i],dq.getmin()+a[i]);
    }
    cout<<dp[n-1]<<nl;
}

int cp[1000][1000];
int opt(int i,int j){  //min cost path from 1 to i
       if(i==0 && j==0){return 0;}
       else if(i==1){return 1e9;}
       if(cp[i][j]!=-1)return cp[i][j];
       int ans= opt(i-1,j)+b[i-1];
       if(j>0){
        for(int z=1;i-z>=0 && z<=k;j++){
          ans=min(ans,opt(i-z,j-1)+a[i]+a[i-z]);
       }}
       return cp[i][j]=ans;
}
void solve2(){
     input();
     for(int j=0;j<=m;j++){
        for(int i=1;i<=n;i++){
           if(i==0 && j==0){cp[j][i]=0;}
           else if(i==1){cp[j][i]=1e9;}
           cp[j][i] = cp[j][i-1] +b[i-1];
           if(j>0){
               for(int z=1;i-z>=0 && z<=k;j++){
               cp[j][i]=min(cp[j][i],cp[j-1][i-z]+a[i]+a[i-z]);
               };
            }
        }
     }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif 

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}