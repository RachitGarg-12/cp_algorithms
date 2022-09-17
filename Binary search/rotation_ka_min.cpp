 // find rotation in sorted array 
 // number of rotation = index of smallest element


ll rotation(vector<ll> &b){
           int rotation;
           int low=0;int high=n-1;int mid= low + ( high - low)/2;;
           while(low<=high){
                if(low==high){rotation=low;break;}
                mid= low + ( high - low)/2;
                if(b[mid]<b[mid-1]){rotation = mid;break;}
                else if(b[mid]>b[mid+1]){rotation = mid+1;break;}
                else if(b[mid] > b[n-1]){low = mid+1 ;}
                else if(b[mid] < b[n-1]){high = mid-1;}
           }

           retun rotation;

}


int findMin(vector<int>& b) {
        int n=b.size();
        int l=0;int r=n-1;
        while(l<r){
            int m= l +(r-l)/2;
            if(b[m]>b[n-1]){l=m+1;}
            else{r=m;}
        }
    return b[l];
    }