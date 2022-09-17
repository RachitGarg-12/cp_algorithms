     //Rachit Garg
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define all(arr) arr.begin(), arr.end()
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
    ll maxpow2(ll n){
    ll ans;
        for(ll i=0;i<=32;i++){
            ll m = (ll)1<<i;
           if(m>n){ans=i-1;break;}
        }
        return ans;
        
    } 
    
    bool gettogether(vector<pair<ll,ll>> part,long double m,ll n){
           
           long double left1= part[0].first - part[0].second*m;
           long double right1= part[0].first + part[0].second*m;
           long double start = left1;long double end= right1;
           f1(i,n-1){ 
            long double left2= part[i].first - part[i].second*m;
            long double right2= part[i].first + part[i].second*m;
            if(max(start,left2) <= min(end,right2)){start=max(start,left2);end=min(right2,end);}
            else{return false;}
           }


           return true;

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
      
        ll n;cin>>n;
        vector<pair<ll,ll>> part;
        fo(i,n){
            ll x,y;cin>>x>>y;
            part.push_back({x,y});
        }
        sort(all(part));
        long double l=0, r=1e18;long double eps=1e-7;ll ans=1e18;
        while(r-l>eps){
            long double m = l +(r-l)/2;
            if(gettogether(part,m,n)){ans=m;r=m-eps;}
            else{l=m+eps;}
        }
        cout<<fixed<<setprecision(12)<<ans;

        // if(gettogether(part,l,n)){cout<<fixed<<setprecision(12)<<l<<"\n";}
        // else{cout<<fixed<<setprecision(12)<<r<<"\n";}
        

            return 0;
        
        
        }