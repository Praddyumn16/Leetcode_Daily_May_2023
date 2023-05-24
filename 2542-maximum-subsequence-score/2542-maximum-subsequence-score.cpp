class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long ans = 0 , n = nums1.size();
        
        vector<pair<int , int>> v;
        priority_queue<int , vector<int> , greater<>> pq;
        
        for(int i = 0 ; i < n ; i++) 
            v.push_back({nums2[i] , nums1[i]});
        
        sort(v.begin() , v.end());
        
        long long sum = 0 , mini = INT_MAX;
        
        for(int i = n - k ; i < n ; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
        }
        
        ans = v[n - k].first * sum;
        
        for(int i = n - k - 1 ; i >= 0 ; i--) {
            
            sum = sum - pq.top() + v[i].second;
            
            pq.pop();
            pq.push(v[i].second);
            
            ans = max(ans , sum * v[i].first);
        }
        
        return ans;
    }
};