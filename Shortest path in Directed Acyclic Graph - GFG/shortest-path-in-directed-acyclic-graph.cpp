//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int i, stack<int>& s, vector<int>& vis, vector<vector<pair<int , int>>>& adj) {
        
        vis[i] = 1;
        
        for(auto neighbor : adj[i]) 
            if(!vis[neighbor.first]) 
                dfs(neighbor.first , s, vis, adj);
        
        s.push(i);
    }
    
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int , int>>> adj(n);
        
        for(auto a : edges)
            adj[a[0]].push_back({a[1] , a[2]});
        
        vector<int> vis(n , 0);
        stack<int> s;
        
        for(int i =  0 ; i < n ; i++)
            if(!vis[i]) dfs(i, s, vis, adj);
        
        vector<int> dis(n , INT_MAX);
        dis[0] = 0;
        
        while(s.top() != 0) {
            dis[s.top()] = -1;
            s.pop();
        }
        
        while(!s.empty()) {
            int curr = s.top();
            // cout << curr << ", ";
            s.pop();
            for(auto neighbor : adj[curr]) {
                dis[neighbor.first] = min(dis[neighbor.first] , dis[curr] + neighbor.second); 
            }
        }
        
        // for(int i = 0 ; i < n ; i++)
        //     if(dis[i] == INT_MAX)
        //         dis[i] = -1;
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends