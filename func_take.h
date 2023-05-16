void take(long n, long K,long* items, long k, long s,long* c[],long* data[],long no){
    if(c[k][s]==0){
        return;
    } 
    if(c[k-1][s]==c[k][s]){
        take(n,K,items,k-1,s,c,data,no);
    }
    else{ 
        items[no]=k+1;
        take(n,K,items,k-1,s-data[k][1],c,data,no+1);
    }
}