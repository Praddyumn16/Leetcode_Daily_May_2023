class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int count_neg = 0;
        
        for(auto a : nums) {
            if(a == 0)
                return 0;
            else if(a < 0)
                count_neg++;
        }
        
        return (count_neg % 2 ? -1 : 1);
    }
};