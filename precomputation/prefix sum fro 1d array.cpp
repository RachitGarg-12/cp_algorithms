#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){

    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        ll n;cin>>n;
        ll l,r;cin>>l>>r;
        ll a[n];ll pf[n];
        pf[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            pf[i]=pf[i-1]+a[i];
        }
        cout<<pf[r]-pf[l-1]<<endl;  //sum from l to r
       

    return 0; 
    
}