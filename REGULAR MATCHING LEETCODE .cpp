// REGULAR MATCHING LEETCODE 100%FAST

bool solve(string pattern, string s) {
    
    int n=pattern.size();
    int m=s.size();

    bool dp[n+1][m+1];

    for(int j=0;j<=m;j++){
        dp[0][j]=false;
    }
    dp[0][0]=true;
    for(int i=1;i<=n;i++){
        
        if(pattern[i-1]=='*'){
            dp[i][0]=dp[i-2][0];
        }
        else{
            dp[i][0]=false;
        }
    }

    // loop

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(pattern[i-1]=='.'){
                dp[i][j]=dp[i-1][j-1];
            }
            else if(pattern[i-1]=='*'){

                dp[i][j]=dp[i-2][j];

                if(pattern[i-2]==s[j-1] || pattern[i-2]=='.'){
                    dp[i][j]=dp[i][j] || dp[i][j-1];
                }

            }
            else{

                if(pattern[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
    }

    return dp[n][m];
}