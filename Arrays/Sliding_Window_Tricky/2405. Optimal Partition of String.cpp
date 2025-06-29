class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> mp;
        int n = s.size(), total = 0, start = 0;

        for(int i=0;i<n;i++){
            mp[s[i]]++;
    
            if(mp[s[i]] > 1) {
                total++;
                mp.clear();
                mp[s[i]]++;
            }
        }

        return total+1;
    }
};