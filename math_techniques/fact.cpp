 ll fact[100];
        fact[0]=1;fact[1]=1;
         for(ll i=2;i<=11;i++){
            fact[i]=fact[i-1]*i;
         }