class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int , bool> mp1 , mp2;
        
        for(auto a : nums1)
            mp1[a] = 1;
        
        for(auto a : nums2)
            mp2[a] = 1;
        
        vector<vector<int>> ans(2);
        
        for(auto a : nums1) {
            if(mp1[a] && !mp2[a]){
                ans[0].push_back(a);
                mp1[a] = 0;
            }
        }
        
        for(auto a : nums2) {
            if(mp2[a] && !mp1[a]){
                ans[1].push_back(a);
                mp2[a] = 0;
            }
        }
        
        return ans;
    }
};