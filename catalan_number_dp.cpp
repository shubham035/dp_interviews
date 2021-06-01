#include<bits/stdc++.h>
using namespace std;

long long int catalan(int n){

    long long int dp[n+1]={0};

    dp[0]=dp[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=1ll*dp[j]*dp[i-j-1];
        }
    }

    return dp[n];
}

// T(n)=for (int i=0 to i=n) T[n+1]=T(i)*T(n-i-1)
// c0=c1=1;                      
// Time complexity of above implementation is O(n^2)
// space complexity O(n^2);
int main(){

    int n;
    cin>>n;

    long long int ans=catalan(n);
    cout<<ans<<endl;
    return 0;
}