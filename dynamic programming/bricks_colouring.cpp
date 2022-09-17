#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define um unordered_map
#define us unordered_set
#define f first
#define s second
#define v vector
#define all(arr) arr.begin(), arr.end()
template <typename T> istream& operator>>(istream &istream, vector<T> &nums){ for(auto &val: nums) cin >> val; return istream;}
template <typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p){ return (istream >> p.f >> p.s);}
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...);}
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')';}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NONI_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
v<v<int>> dp;

int solve(int level, int left, int n, int m){
    if (level == n+1){
        if (left == 0)
        return 1;
        return 0;
    }

    if (dp[level][left] != -1)  return dp[level][left];
    int ans = 0;
    if (level == 1){
        ans = (solve(level+1, left, n, m) * m) % mod;
    }
    else {
        // same as previous
        if (n-level >= left) ans = solve(level+1, left, n, m);
        // different from the previous
        if (left >= 1)    ans = (ans + (solve(level+1, left-1, n, m) * (m-1)) % mod);
    }

    return dp[level][left] = ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;cin >> t;
    while(t--){
        int n, m, k;cin >> n >> m >> k;
        dp.assign(n+1, v<int> (k+1, -1));
        cout << (solve(1, k, n, m) % mod) << "\n";
    }

}