#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
#define mod 1000000007
using namespace std;

int n,k;
vector<int>vec(101);
int dp[100001];

bool rec(int stones){
    // returns a player can win or not if he has to play first
    // with these stones

    if(stones==0) return 0;
    if(stones<0) return 1;
    if(dp[stones]!=-1) return dp[stones];

    int ans=1;

    for(int i=0;i<n;i++){
        ans &= rec(stones-vec[i]);
    }
    ans^=1;

    return dp[stones] = ans;
}

// check int overflow
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>vec[i];

    memset(dp,-1,sizeof dp);

    (rec(k))?cout<<"First"<<nn:cout<<"Second"<<nn;
}   
 
int main()
{
 
    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    //scanf("%d",&tc);  
    while(tc--){
        solve();
    }
    return 0;
}