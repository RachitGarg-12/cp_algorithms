
//factors always occurs in pairs and max value of smaller number of pair is root(n)
vector<ll> factors(ll n){
        vector<ll> ans;
        if(n==1){ans.push_back(1);}

        for(ll i=2;i*i<=n;i++){
            if(n%i==0){
                if(i == n/i){ans.push_back(i);}
                else{ans.push_back(i);ans.push_back(n/i);}
            }
        }
        return ans;
    }