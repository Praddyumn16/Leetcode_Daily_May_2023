class Solution {
public:
    void solve(string curr_node , string dest , double curr_ans , unordered_map<string , vector<pair<string , double>>>& adj_list , set<double>& temp , unordered_map<string , bool>& visited) {
        if(curr_node == dest) {
            temp.insert(adj_list.count(curr_node) ? curr_ans : -1.0);
            return;
        }

        visited[curr_node] = 1;

        for(auto neighbor : adj_list[curr_node]) {
            if(!visited[neighbor.first])
                solve(neighbor.first , dest , curr_ans * neighbor.second , adj_list , temp , visited);
        }
        
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string , vector<pair<string , double>>> adj_list;
        
        for(int i = 0 ; i < values.size() ; i++) {
            adj_list[equations[i][0]].push_back({equations[i][1] , values[i]});
            adj_list[equations[i][1]].push_back({equations[i][0] , 1.0 / values[i]});
        }
        
        vector<double> ans;

        for(auto a : queries) {
            set<double> temp;
            unordered_map<string , bool> visited;
            solve(a[0] , a[1] , 1.0 , adj_list , temp , visited);
            int num_of_ans = temp.size();
            ans.push_back(num_of_ans == 0 || num_of_ans > 1 ? -1.0 : *temp.begin());
        }

        return ans;
    }
};