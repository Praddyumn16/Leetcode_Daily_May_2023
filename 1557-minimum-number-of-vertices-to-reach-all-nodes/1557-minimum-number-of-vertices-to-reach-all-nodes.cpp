class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> ans;
        vector<bool> incoming(n , 0);

        for(auto a : edges) 
            incoming[a[1]] = 1;
        
        for(int i = 0 ; i < n ; i++)
            if(!incoming[i])
                ans.push_back(i);
        
        return ans;
    }
};