class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');    
    }
    
    
    int maxVowels(string s, int k) {
        
        int ans = 0;
        
        for(int i = 0 ; i < k ; i++)
            if(isVowel(s[i])) ans++;
        
        int curr = ans;
        
        for(int i = k ; i < s.size() ; i++) {
            if(isVowel(s[i - k]))
                curr--;
            if(isVowel(s[i]))
                curr++;
            ans = max(ans , curr);
        }
        
        return ans;
    }
};