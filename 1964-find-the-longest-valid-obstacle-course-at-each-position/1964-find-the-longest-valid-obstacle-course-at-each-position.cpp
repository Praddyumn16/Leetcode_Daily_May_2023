class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<int> lis = {obstacles[0]};
        vector<int> ans(n , 1);
        
        for(int i = 1 ; i < n ; i++) {
            if(obstacles[i] >= lis.back()) {
                lis.push_back(obstacles[i]);
                ans[i] = lis.size();
            }
            else {
                int idx = upper_bound(lis.begin() , lis.end() , obstacles[i]) - lis.begin();
                lis[idx] = obstacles[i];
                ans[i] = idx + 1;
            }
        }
        
        return ans;
    }
};