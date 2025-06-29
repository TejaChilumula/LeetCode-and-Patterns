class Solution {
public:
    vector<int> partitionLabels(string s) {

        // Greedy + Hashing
        // We often think of Sliding window, but we have to thnik OOB
        /*
            Here, we need the last occurance index of each element, so that and for a partition we store the max of last occurance of elements in that partition

            - end = max(end, last[s[i] - 'a']);  which stores the max last idx of char in the partition

            so if i reaches the max, it means this char is the max end of that partition and safely after this max elements in partition wont be present
        */


        unordered_map<int, int> last;
        vector<int> tar;

        // store last occurance.
        for(int i=0;i<s.size();i++){
            last[s[i]-'a'] = i;
        }
        int end = 0, start = 0;
        for(int i=0;i<s.size();i++){
            end = max(end, last[s[i]-'a']);

            if(end == i){// this is the last of partition chars
                tar.push_back(end-start+1);
                start = i+1;
            }
        }

        return tar;


        //******* This Approach is OverKill and too complex and wont handle all the edge cases ********
        // stack<vector<char>> stk;
        // vector<char> vec;
        // set<char> sett;
        // for(int i=0;i<s.size();i++){
        //     if(find(vec.begin(), vec.end(), s[i]) != vec.end()) vec.push_back(s[i]);
        //     else if(sett.count(s[i])){
        //         while(!stk.empty()){
        //             vector<char> top = stk.top();
        //             stk.pop();
        //             top.insert(top.end(), vec.begin(), vec.end());
        //             if(find(top.begin(), top.end(), s[i]) != top.end()){
        //                 stk.push(top);
        //                 vec.clear();
        //                 break;
        //             }
        //         }
        //     }
        //     else{
        //         stk.push(vec);
        //         vec.clear();
        //         vec.push_back(s[i]);
        //         sett.insert(s[i]);
        //     }

        //     // if not there , means new char


        // }

        // vector<int> ans;
        // while(!stk.empty()){
        //     vector<char> top = stk.top();
        //     stk.pop();
        //     ans.push_back(top.size());

        // }

        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};