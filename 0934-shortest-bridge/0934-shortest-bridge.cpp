class Solution {
public:    
    void bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& idx) {
        
        if(i < 0 || i == grid.size() || j < 0 || j == grid.size() || grid[i][j] != 1)
            return;
        
        grid[i][j] = 2;
        idx.push_back({i , j});

        bfs(i + 1 , j , grid , idx);
        bfs(i , j + 1 , grid , idx);
        bfs(i , j - 1 , grid , idx);
        bfs(i - 1 , j , grid , idx);
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size() , flag = 0;
        vector<vector<int>> idx; // bfs queue

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j]) {
                    bfs(i , j , grid , idx);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }

        int ans = 0;

        vector<int> dx = {-1 , 1 , 0 , 0};
        vector<int> dy = {0 , 0 , -1 , 1};

        while(idx.size()) {
            
            vector<vector<int>> new_idx;
            
            for(auto a : idx) {

                int i = a[0] , j = a[1];

                for(int dir = 0 ; dir < 4 ; dir++) {
                    
                    int new_i = i + dx[dir] , new_j = j + dy[dir];
                    
                    if(!(new_i < 0 || new_i == n || new_j < 0 || new_j == n || grid[new_i][new_j] == 2)) {
                        
                        if(grid[new_i][new_j] == 1)
                            return ans;
                        else {
                            new_idx.push_back({new_i , new_j});
                            grid[new_i][new_j] = 2;
                        }
                    }
                }

            }

            idx = new_idx;
            ans++;
        }

        return ans;
    }
};