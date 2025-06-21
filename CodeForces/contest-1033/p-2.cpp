#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;


#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

void solve(long long n, long long m) {
    /*
         Rules : we can make a min tree with n divinity and max tree with n*(n+1)/2 divinity
         if m not in between n and n(n+1)/2;
         then remove the excess from the max vertex, in that sense attach it to the less val node
    */

    vector<long long> val(n);

    for(int i=0;i<n;i++){ // dignity of each will be same at start
        val[i] = i+1;
    }

    if(m < n || m > n*(n+1)/2) {
        cout<<-1;
        return;    }

    
    int rem = n*(n+1)/2 - m; // we will get the remaining, need to trim from a max tree,
    // means it should be removed from the large nodes, so that these nodes will be added to the least nodes as childrens

        for(int i= n-1;i>= 0;i--){
            if(rem <= val[i]){
                val[i] = rem;
                rem = 0;
            }
            else{
                rem -= (val[i]-1); // 0 indexed
                val[i] = 1;
            }
            if(rem <= 0) break;
        }

        // we got the parent array which is nothing but the dignity array, 
        /* 1. the max element will be the root
           2. All the left side elements will be its childs root -> left element 1, root -> l e 2 ...
           3. After root, the elements will edge to its divinity node, to the reduced node
        */

        long long root = *max_element(val.begin(), val.end());

        cout<<root<<endl;

        for(int i=0;i<n;i++){
            if(val[i] == i+1) // unchanged i.e left to root
            {
                if(i+1 == root) continue; // its wont point to root ; skip it
                cout<<root<<" "<<i+1<<endl;
            }
            else{
                cout<<val[i]<<" "<<i+1<<endl;
            }
        }
    }


int32_t main() {
    fast_io
    int t = 1;
    //vector<pair<long long>> coords;

    cin >> t; // Uncomment if multiple test cases

    while (t--) {
        long long n, m;
        cin>>n>>m;
        solve(n,m);}
return 0;
}
