class Solution {
public:
    int n1 , n2;
    
    int solve(int i , int j , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>>& dp) {
        if(i == n1 || j == n2)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(nums1[i] == nums2[j]) 
            return dp[i][j] = 1 + solve(i + 1 , j + 1 , nums1 , nums2 , dp);
        
        return dp[i][j] = max(solve(i + 1 , j , nums1 , nums2 , dp) , solve(i , j + 1 , nums1 , nums2 , dp));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        n1 = nums1.size() , n2 = nums2.size();
        
        if(n1 > n2) {
            nums1.swap(nums2);
            n1 = nums1.size() , n2 = nums2.size();
        }
        
        vector<vector<int>> dp(n1 , vector<int>(n2 , -1));
        
        return solve(0 , 0 , nums1 , nums2 , dp);
    }
};