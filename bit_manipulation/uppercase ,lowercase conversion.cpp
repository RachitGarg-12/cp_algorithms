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
        
       char c='A';
       c = c|(1<<5);    //uppercase to lowercase
       cout<<c<<endl;
       char a='b';
       a = a & ~(1<<5);
       cout<<a<<endl;

       char d='S';
       d = d | ' ';
       cout<<d<<endl;

       char f ='s';
       f = f & '_';
       cout<<f<<endl;

       printbinary(59);
       ll t=59;
       ll b= t & ~((1<<(3+1))-1);   // clear lsb bits till ith bit here i=1;
       printbinary(b);
       
       ll p= t & ((1<<(3+1))-1);    //clear msb bits till ith bit
       printbinary(p); 

       //all uppercase;
       string s="TrEe";
       for(ll i=0;i<4;i++){
        s[i] = s[i] & '_';
       }
       cout<<s<<endl;

    //all lowercase
       for(ll i=0;i<4;i++){
        s[i] = s[i] | ' ';
       }
       cout<<s<<endl;
        
       


  return 0; 
}