class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n , vector<int>(n));
        
        int top = 0 , bottom = n - 1 , left = 0 , right = n - 1 , curr = 1;
        
        while(top <= bottom && left <= right) {
            
            // going left to right
            for(int col = left ; col <= right ; col++)
                ans[top][col] = curr++;
            
            // going top to bottom
            for(int row = top + 1 ; row <= bottom ; row++)
                ans[row][right] = curr++;
            
            // going right to left
            if(top != bottom)
                for(int col = right - 1 ; col >= left ; col--)
                    ans[bottom][col] = curr++;
            
            // going bottom to top
            if(left != right)
                for(int row = bottom - 1 ; row >= top + 1 ; row--)
                    ans[row][left] = curr++;
            
            top++ , bottom-- , left++,  right--;
        }
        
        return ans;
    }
};