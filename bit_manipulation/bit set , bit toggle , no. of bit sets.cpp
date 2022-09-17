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
        
       ll n;cin>>n;
       printbinary(n);
        
       //check whether ith bit of n is set or not
       if(n & (1<<2) !=0 ){cout<<"set bit"<<endl;}
       else{cout<<"unset bit"<<endl;}

       //set bit of a number at ith position
        printbinary(n | (1<<2));

       //unset bit of a number at ith position
        printbinary(n & ~(1<<2));

       //toggle bit at ith position, just invert the bit
        printbinary(n ^ (1<<3));
    
      //no. of set bit
        ll count=0;
        for(ll i=31;i>=0;i--){
            if((n&(1<<i))!=0){count++;}       //left shift to just and ith bit by 1, to check 1;
        }
        cout<<count<<endl;
         
        ll co=0;
        for(ll i=31;i>=0;i--){
            if((n>>i)&1==1){co++;}      //right shift to 1st bit , take and by one;
        }
        cout<<co<<endl;

       cout<<__builtin_popcount(n)<<endl;
       cout<<__builtin_popcountll((1LL<<35)-1)<<endl;


  return 0; 
}