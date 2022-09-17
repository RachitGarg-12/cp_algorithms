#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int p=1e3+10;
 ll a[p][p];
 ll pres[p][p];

int main(){

    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
    
    ll m,n;cin>>n>>m;
    ll x,y,c,d;cin>>x>>y>>c>>d;
   
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
           cin>>a[i][j];
           
           pres[i][j]=pres[i][j-1]+pres[i-1][j]-pres[i-1][j-1]+a[i][j];}
           
       }
       cout<<pres[c][d]<<" "<<pres[c][y-1]<<" "<<pres[x-1][d]<<" "<<pres[x-1][y-1]<<endl;
      cout<<pres[c][d]-pres[c][y-1]-pres[x-1][d]+pres[x-1][y-1]<<endl;


    return 0; 
    
}