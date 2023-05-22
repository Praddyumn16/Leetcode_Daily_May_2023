class Solution {
public:
    int n;
    
    int solve(int step , int mask , vector<vector<int>>& dp , vector<int>& nums) {
        if(step == n/2 + 1)
            return 0;
        
        if(dp[step][mask] != -1)
            return dp[step][mask];
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            if((mask & (1 << i)) == 0) {
                for(int j = i + 1 ; j < n ; j++) {
                    if((mask & (1 << j)) == 0) {
                        ans = max(ans , (step * __gcd(nums[i] , nums[j]) + solve(step + 1 , (mask | (1 << i) | (1 << j)) , dp , nums)));
                    }
                }
            }
        }

        return dp[step][mask] = ans;
    }

    int maxScore(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n/2 + 1, vector<int>(pow(2 , n) , -1));
        return solve(1 , 0 , dp , nums);
    }
};