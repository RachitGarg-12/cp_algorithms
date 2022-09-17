#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void  printbinary(ll n){
    ll p= (ll)log2(n);
    for(ll i=p;i>=0;i--){
        cout<< ((n>>i)&1);
    }
    cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE    
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif
        
        //no.of days 30, find 2 workers and maximize no of days
        ll n;cin>>n;
        vector<int> masks(n);

        for(int i=0;i<n;i++){
            int num_days;cin>>num_days;
            int bitmask=0;
            for(int j=0;j<num_days;j++){
                int day;cin>>day;
                bitmask = bitmask | (1<<day) ;
            }
           //printbinary(bitmask);
            masks[i]=bitmask;
        }
        
        int max_days=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 int h=masks[i] & masks[j];
                 int intersec = __builtin_popcount(h);
                max_days= max(max_days,intersec);
            }
        }
         cout<<max_days;
        
       
        
       


  return 0; 
}