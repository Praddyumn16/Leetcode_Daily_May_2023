class Solution {
public:
    long long minimumCost(string s) {
        
        long long ans = 0 , n = s.size();
        
        for(long long i = 1 ; i < n ; i++)
            if(s[i] != s[i - 1])
                ans += min(i , n - i);
        
        return ans;
    }
};