class Solution {
public:
    int numTilePossibilities(string tiles) {

    // so you just need a count, why to build the entire sub strings.

    unordered_map<char, int> freq;
    for(int i=0;i<tiles.size();i++) freq[tiles[i]]++;
    int total = 0;
    helper2(tiles, freq, total);
    return total;
    }

    // Using Set + Count + erase on substr at each step.
    //     set<string> ans;
    //     vector<bool> seen(tiles.size(), false);

    //     helper(tiles,ans, "", seen);
    //     for(auto i: ans) cout<<i<<" ";
    //     return ans.size()-1;
    // }

    // void helper(string tiles, set<string>& ans, string lcl_str, vector<bool> seen){
    //     if(ans.count(lcl_str)) return;
    //     if(lcl_str.size() == tiles.size()) {
    //         ans.insert(lcl_str);
    //         return;
    //     }

    //     ans.insert(lcl_str);

    //     for(int i=0;i<tiles.size();i++){
    //         if(!seen[i]){
    //             lcl_str+=tiles[i];
    //             seen[i] = true;
    //             helper(tiles, ans, lcl_str,seen);
    //             seen[i] = false;
    //             lcl_str = lcl_str.erase(lcl_str.size()-1);
    //         }
    //     }
    // }

    void helper2(std::string tiles, unordered_map<char, int> freq, int& total){

        for(auto& [c, count] : freq){
            if(count == 0) continue;
                
                freq[c]--;
                total++;
                helper2(tiles,freq,total);
                freq[c]++;
            
        }
    }

};