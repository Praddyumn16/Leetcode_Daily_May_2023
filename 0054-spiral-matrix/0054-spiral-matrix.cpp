class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int m = matrix.size() , n = matrix[0].size();
        
        int top = 0 , bottom = m - 1 , left = 0 , right = n - 1;
        
        while(top <= bottom && left <= right) {
            
            // going left to right
            for(int col = left ; col <= right ; col++)
                ans.push_back(matrix[top][col]);
            
            // going top to bottom
            for(int row = top + 1 ; row <= bottom ; row++)
                ans.push_back(matrix[row][right]);
            
            // going right to left
            if(top != bottom)
                for(int col = right - 1 ; col >= left ; col--)
                    ans.push_back(matrix[bottom][col]);
            
            // going bottom to top
            if(left != right)
                for(int row = bottom - 1 ; row >= top + 1 ; row--)
                    ans.push_back(matrix[row][left]);
            
            top++ , bottom-- , left++,  right--;
        }
        
        return ans;
    }
};