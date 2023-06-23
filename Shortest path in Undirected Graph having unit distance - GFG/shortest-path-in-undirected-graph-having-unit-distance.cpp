//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        
        vector<vector<int>> adj(n);
        for(auto a : edges) {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        
        vector<int> vis(n , 0);
        vector<int> dis(n , INT_MAX);
        
        queue<pair<int , int>> q;
        q.push({src , 0});
        vis[src] = 1;
        
        while(!q.empty()) {
            int curr = q.front().first , len = q.front().second;
            dis[curr] = len;
            q.pop();
            for(auto neighbor : adj[curr]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor , 1 + len});
                }
            }
        }
        
        for(auto &a : dis)
            if(a == INT_MAX) a = -1;
            
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends