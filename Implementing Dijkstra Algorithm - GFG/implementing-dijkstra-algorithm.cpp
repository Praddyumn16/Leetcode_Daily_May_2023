//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

typedef pair<int , int> pi;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int> dist(v , INT_MAX);
        dist[s] = 0;
        
        priority_queue<pi, vector<pi> , greater<pi>> pq;
        pq.push({0 , s});
        
        while(!pq.empty()) {
            int dis = pq.top().firsy;
            pq.pop();
            for(auto neighbor : adj[curr.second]) {
                int curr_dis = curr.first + neighbor[1];
                if(dis[neighbor[0]] < curr_dis) {
                    dis[neighbor[0]] = curr_dis;
                    pq.push({curr_dis , neighbor[0]});
                }
            }
        }
        
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends