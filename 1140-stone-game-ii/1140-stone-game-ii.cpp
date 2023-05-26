class Solution {
public:
    int solve(int idx , int m , vector<int>& sum , vector<int>& piles , vector<vector<int>>& dp) {
        
        if(idx >= piles.size())
            return 0;
        
        if(piles.size() - idx <= 2 * m)
            return sum[idx];
        
        if(dp[idx][m] != -1)
            return dp[idx][m];
        
        int nextPersonPiles = INT_MAX;
        
        for(int i = 1 ; i <= (2 * m) ; i++)
            nextPersonPiles = min(nextPersonPiles , solve(idx + i , max(i , m) , sum , piles , dp));
        
        return dp[idx][m] = sum[idx] - nextPersonPiles;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        
        vector<int> sum(n , piles[n - 1]);
        
        for(int i = n - 2 ; i >= 0 ; i--)
            sum[i] = sum[i + 1] + piles[i];
        
        vector<vector<int>> dp(n , vector<int>(n , -1));
        
        return solve(0 , 1 , sum , piles , dp);
    }
};