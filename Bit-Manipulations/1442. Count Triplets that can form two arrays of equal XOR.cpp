class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // we need to find out the way where i^i1^i2^i3^i4^^ == j^^^^k
        /*  
        Prefix Sum - O(n^2)
            - for that we dont need to find out the j, cause we already have k, 
                - no of valid triplets we can form is k - i + 1, i.e i+1 becz, i < j
                - how k - i + 1, if prefiXor[i] == prefiXor[k] , it means that
                  prefiXor[i] ....... prefiXor[k], all the middle elements are concelling out
        
        int n = arr.size();
        vector<int> prefiXor(n+1,0);

        for(int i=0;i<n;i++) prefiXor[i+1] = prefiXor[i]^arr[i];
        int ans = 0;
        for(int i=0;i<n;i++){

            for(int k=i+1;k<n;k++){
                if(prefiXor[i] == prefiXor[k+1]) 
                    ans += k - i ;
            }
        }

        return ans; */

        // O(N) - approach , same as O(N^2), but instead of finding all the i's for a k, we can make a 
        /* count of no of i occurances where it equals to k prefiXor, so that
                - O(N^2) -- we do prefiXor[i] == prefiXor[k+1] , for i1, i2, i3,....
                 - we can make a count of these on the go, countofI's and their indexes that's what we need to find out the valid triplets

                        O(N) - ans += k * countofI's - (indexofI's)
        */

        unordered_map<int,int> countofI, indicesSumofI;
        int n = arr.size(), ans = 0;
        vector<int> prefiXor(n+1,0);

        for(int i=0;i<n;i++) prefiXor[i+1] = prefiXor[i]^arr[i];
        // 0th idex and no of i's = 1
        countofI[0] = 1, indicesSumofI[0] = 0;

        for(int k = 1; k<=n;k++){
            int x = prefiXor[k];
            ans += k * countofI[x] - indicesSumofI[x] - 1 * countofI[x];
            countofI[x]++;
            indicesSumofI[x] += k;
        }

        return ans;
     }
};