class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int maxL = 1;
        int idx = 0;

        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int L = 2;L<=n;L++){
            for(int i = 0;i+L-1<n;i++){
                int j = i + L - 1;
                if(s[i] == s[j] && L == 2){
                    dp[i][j] = 1;
                    maxL = 2;
                    idx = i;
                }else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if(L > maxL){
                        maxL = L;
                        idx = i;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(idx,maxL);
    }
};