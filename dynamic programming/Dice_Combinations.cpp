     //Rachit Garg
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define all(arr) arr.begin(), arr.end()
    #define nl "\n"
    #define ce  cout<<endl
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
    #define mod 998244353
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

    ll lcm(ll  a, ll b)
    {
        return (a/__gcd(a,b))*b ;
    }
    
    bool ch(string s,string a){
        ll pos=0;
        ll n=s.length();ll o=a.length();
        for(ll i=0;i<n;i++){
            if(pos==o){pos=0;}
            if(a[pos]!=s[i]){return false;}
            pos++;
        }
        return true;
    }
    bool prime(int n){
        if(n<0){
            return false;
        }
        for(int i =2;i*i<n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    bool palindrome(int n){
        int r,sum = 0,k;
        k = n;
        while(n>0){
        r = n%10;
        sum = sum * 10 + r;
        n = n/10;
    }
        if( k == sum){
            return true;
        }
        else{
            return false;
        }
    }

    bool isPalindrome(string S)
    { for (int i = 0; i < S.length() / 2; i++) {
            if (S[i] != S[S.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    pair<ll,ll> powg2(ll n){
    ll i,ans;
        for(i=1;i<=32;i++){
            ll m = n*((ll)1<<i);
           if(m>32768){ans=n*((ll)1<<(i-1));break;}
        }
        return {ans,i-1};
        
    } 

    /////////////////////////////////////   
        
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // #ifndef ONLINE_JUDGE    
        // freopen("input.txt", "r", stdin); 
        // freopen("output.txt", "w", stdout);
        // freopen("error.txt", "w", stderr);
        // #endif 
        
            const ll m= 1e9+7;
            ll n;cin>>n;
            vector<ll> dp(n+1,0);//dp[i] is the number of ways we can get sum i in a dice on any num of rolling
            dp[0]=1;
            //here the observation is that for all sums, the number of possible ways sum ending
            //with 1 are dp[i-1], ending with 2 are dp[i-2] , ...
            //no formula was formed in sequence of dp , so try to relate with numbers on dice
            // so we relatewd with [i-1][i-2][i-3]..[i-6]
            for(ll i=1;i<=n;i++){
                for(int j=1;j<=6 && i>=j;j++){
                dp[i]+=dp[i-j]%m;}
                dp[i]%=m;
            }
             cout<<dp[n]<<nl;
            return 0;
        }