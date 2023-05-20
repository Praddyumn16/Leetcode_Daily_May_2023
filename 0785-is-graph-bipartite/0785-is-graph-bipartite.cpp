class Solution {
public:
    bool dfs(int curr , vector<int>& color , vector<vector<int>>& graph) {

        for(auto neighbor : graph[curr]) {
            if(color[curr] == -1 && color[neighbor] == -1) {
                color[curr] = 0;
                color[neighbor] = 1;
            }
            else if(color[neighbor] == -1)
                color[neighbor] = !color[curr];
            else if(color[curr] == color[neighbor])
                return false;
            else
                continue;
            if(!dfs(neighbor , color , graph))
                return false;
        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n , -1);
        
        for(int i = 0 ; i < n ; i++) {
            if(color[i] == -1) {
                if(dfs(i , color , graph) == false)
                    return false;
            }
        }

        return true;
    }

};