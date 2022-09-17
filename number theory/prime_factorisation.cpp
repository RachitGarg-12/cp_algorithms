//finding smallest prime factor for 1 to n
vector<ll> smallestprime;
    void smallestprimefactor(int n){
           smallestprime.resize(n+1 , -1);
           for(int i=2;i<=n;i++){
             if(smallestprime[i]==-1){
                smallestprime[i]= i;
                for(int j=i*i;j<=n;j +=i){
                    if(smallestprime[j]==-1 || smallestprime[j]>i){smallestprime[j]=i;}
                }
             }
           }
           
    }

//prime factorisation of n
    vector<pair<int,int>> queryfactorisation(int n){
        vector<pair<int,int>> primefactorisation;
        while(n>1){
            int val = smallestprime[n]; int k=0;
            while(n%val ==0 ){ n /= val;k++;}
            primefactorisation.pb({val,k});
        }
        return primefactorisation;
    }