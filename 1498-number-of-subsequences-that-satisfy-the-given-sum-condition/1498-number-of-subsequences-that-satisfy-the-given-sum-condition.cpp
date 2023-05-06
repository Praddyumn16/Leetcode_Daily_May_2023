class Solution {
public:
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        
        int res = 0 , mod = 1e9 + 7 , n = nums.size();
        
        int l = 0 , r = n - 1;
        
        vector<int> pow(n , 1);
        
        for(int i = 1 ; i < n ; i++)
            pow[i] = (pow[i - 1] * 2) % mod;
        
        while(l <= r) {
            if(nums[l] + nums[r] > target)
                r--;
            else {
                int curr = pow[r - l++] % mod;
                res = (res + curr) % mod;
            }
        }
        
        return res;
    }
};