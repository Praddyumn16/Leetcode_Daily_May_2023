class Solution {
public:
    int mod = 1e9 + 7;
    
    int solve(int len , int curr_len , int zero , int one , vector<int>& dp) {
        if(curr_len >= len)
            return (curr_len == len);
        
        if(dp[len - curr_len] != -1)
            return dp[len - curr_len];
        
        int use_zero = solve(len , curr_len + zero , zero , one , dp);
        int use_one = solve(len , curr_len + one , zero , one , dp);
        
        return dp[len - curr_len] = (use_zero + use_one) % mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int ans = 0;
        vector<int> dp(high + 1 , -1);
        
        for(int i = low ; i <= high ; i++) {
            int curr = solve(i , 0 , zero , one , dp);
            ans = (ans + curr) % mod;  
        }
        
        return ans;
        
    }
};