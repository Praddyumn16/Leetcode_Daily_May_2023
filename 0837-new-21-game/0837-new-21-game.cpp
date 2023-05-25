class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        
        vector<double> dp(n + 1 , 0);
        dp[0] = 1.0;

        double ans = 0.0 , prob = (1.0 / maxPts) , sum = (k ? 1 : 0);

        for(int i = 1 ; i <= n ; i++) {
            
            dp[i] = sum * prob;
            
            // for(int j = max(0 , i - maxPts) ; j < min(i , k) ; j++)
            //     dp[i] += dp[j];
            
            if(i < k)
                sum += dp[i];
            if(i - maxPts >= 0 && i - maxPts < k)
                sum -= dp[i - maxPts];

            if(i >= k)
                ans += dp[i];
        }

        return (!ans ? 1 : ans);
    }
};