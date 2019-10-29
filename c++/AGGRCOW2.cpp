#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e17
#define si 400005
#define piv pair<int ,vector<int>>


ll powmod(ll a, ll b){ ll ans = 1; while(b){if(b&1)ans=(ans%M*a%M)%M; a=(a%M*a%M)%M; b=b>>1;}return ans;}
int n,c,b[1000005];
bool fun(int minm){
    int i,ncow,prev,curr,df;
    prev=b[0];ncow=1;
    for(i=1;i<n;i++){
        curr=b[i];
        df=curr-prev;
        if(df>=minm){
            ncow++;
            prev=curr;
        }
        if(ncow==c)
            return true;
    }
    return false;
}
int bin_search(int l, int r){
    int m;
    while(l<r){
        m = l  + (r-l+1)/2;
        if(fun(m))
            l=m;
        else
            r=m-1;
    }
    return l;
}
int main(){
    boost
    int t,i,ans,r;
    cin>>t;
    while(t--){
        cin>>n>>c;
        for(i=0;i<n;i++){
            cin>>b[i];
        }
        sort(b,b+n);
        r=(b[n-1]-b[0])/c+1;
        ans = bin_search(1,r);
        cout<<ans<<"\n";
    }
    return 0;
}
