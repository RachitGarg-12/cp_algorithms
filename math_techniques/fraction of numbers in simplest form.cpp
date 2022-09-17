#include <iostream>
#include<cmath>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x,y;
    cin>>x>>y;
    int g=__gcd(x,y);
    x /= g;
    y /= g;
    cout<<x<<"/"<<y<<endl;
    
}
