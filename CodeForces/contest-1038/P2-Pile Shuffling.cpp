/*
    Problem - 2
        You are given 𝑛 binary piles, the 𝑖 -th of which consists of 𝑎𝑖 zeros on the top and 𝑏𝑖
 ones on the bottom.

In one operation, you can take the top element of any pile and move it to any position in any pile, including the pile it was taken from.

Solution of the first example test case.
Calculate the minimum number of operations required to make it so that the 𝑖
-th pile consists of 𝑐𝑖
 zeros on the top and 𝑑𝑖
 ones on the bottom.
Input
Each test contains multiple test cases. The first line contains the number of test cases 𝑡
 (1≤𝑡≤104). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛 (1≤𝑛≤2⋅105) — the number of piles.

Then 𝑛 lines follow, the 𝑖-th containing four integers 𝑎𝑖, 𝑏𝑖, 𝑐𝑖, 𝑑𝑖(0≤𝑎𝑖,𝑏𝑖,𝑐𝑖,𝑑𝑖≤109) — the original and target state of the 𝑖-th pile.

It is guaranteed that there exists a sequence of operations that transforms the piles into the target state.

It is guaranteed that the sum of 𝑛over all test cases does not exceed 2⋅105
*/


#include <vector>
#include<iostream>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int solve(int &n, vector<pair<int,int>>& piles, vector<pair<int, int>>&req_piles) {
    
    //cout<<"n: " <<n<<endl;
    int ans = 0;

    for(int i=0;i<n;i++){
        int extraOnes = 0, extraZeros = 0;
        if(piles[i].first >= req_piles[i].first)
            extraZeros = piles[i].first - req_piles[i].first;
        
        if(piles[i].second >= req_piles[i].second){
            extraOnes = piles[i].second - req_piles[i].second;
            int zeroes_above = min(extraOnes, piles[i].first);
            extraOnes += zeroes_above;
        }

        ans += extraOnes;
        ans += extraZeros;
        //cout<<"Iteration: 1 "<<ans<<"ExtraOnes : "<<extraOnes<<" ExtraZeroes: "<<extraZeros<<endl;
     }

    return ans;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--){

        int n, a,b,c,d;
        cin>>n;
        vector<pair<long long, long long>> piles;
        vector<pair<long long,long long>> req_piles;
        
        for(int i=0;i<n;i++){
            cin>>a>>b>>c>>d;
            piles.push_back({a,b});
            req_piles.push_back({c,d});
        }
        
        cout<<solve(n, piles, req_piles)<<endl;
    } 
    return 0;
}
