class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> dire;
        queue<int> radiant;
        
        int n = senate.size();
        
        for(int i = 0 ; i < n ; i++)
            (senate[i] == 'R' ? radiant.push(i) : dire.push(i));
        
        while(!dire.empty() && !radiant.empty()) {
            if(dire.front() < radiant.front()) 
                dire.push(n++);
            else
                radiant.push(n++);
            dire.pop();
            radiant.pop();
        }
        
        return (!dire.empty() ? "Dire" : "Radiant");
    }
};
