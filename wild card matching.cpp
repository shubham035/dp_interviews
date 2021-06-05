// WILDCARD MATCHING LEETCODE 44

class Solution {
public:
    bool isMatch(string s, string pattern) {
        
        // naive approach
        
        // ? daigonal
        // * different case
        // a-z simple check for smaller  values
        // bottom up approach first filling the n,m index then going upward
        // the nth ,mth charcter is empty string for dp[n][0] or dp[0][m];
        int m=s.length();
        int n=pattern.length();
        
        bool dp[n+1][m+1];
        
        // initialisation 
        
        for(int j=m;j>=0;j--){
            dp[n][j]=false;
        }
        dp[n][m]=true;
        
        for(int i=n-1;i>=0;i--){
            
            if(pattern[i]=='*'){
                dp[i][m]=dp[i+1][m];
            }
            else{
                dp[i][m]=false;
            }
            
        }
        
        // our nth row  and mth column in initialised
        
        // loop to fill the matrix
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                if(pattern[i]=='?'){
                    dp[i][j]=dp[i+1][j+1];
                }
                else if(pattern[i]=='*'){
                    dp[i][j]=dp[i+1][j] || dp[i][j+1];
                    
                }
                else{
                    
                    if(pattern[i]==s[j]){
                        dp[i][j]=dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        // return when both the string ,pattern all character are taken into consideration
        
        return dp[0][0];
        
    }
};