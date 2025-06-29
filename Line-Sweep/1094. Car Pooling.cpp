class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        /*vector<int> overlap_trip(3,0);

        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });


        vector<int> timeline(1001,0);

        for(int i=0;i<trips.size();i++){
            for(int j = trips[i][1] ; j<trips[i][2];j++){
                int current_trip_passengers = trips[i][0];
                if(timeline[j] + current_trip_passengers > capacity) return false;
                timeline[j] += current_trip_passengers;
            }
        }

        return true; */

        // overlap_trip[0] = trips[0][0];
        // overlap_trip[1] = trips[0][1];
        // overlap_trip[2] = trips[0][2];

        // if(overlap_trip[0] > capacity) return false;

        // for(int i=1;i<trips.size();i++){
        //     if(overlap_trip[2] <= trips[i][1]){
        //         overlap_trip[0] = trips[i][0];
        //         overlap_trip[1] = trips[i][1];
        //         overlap_trip[2] = trips[i][2];
        //                     }
        //     else{
        //         if(overlap_trip[0] + trips[i][0] > capacity) return false;
        //         else{
        //             overlap_trip[0] = overlap_trip[0] + trips[i][0];
        //             overlap_trip[1] = max(overlap_trip[1], trips[i][1]);
        //             overlap_trip[2] = max(overlap_trip[2], trips[i][2]);
        //         }
        //     }
        // }
        // return true;




        // *********** LINE SWEEP SOLUTION ******************


        // the above solution is a partial line sweep solution where you are iterating on each trip, might end up doing for atmost 1000 trips not optimal and not a pure LINE SWEEP solution

        vector<int> timeline(1001, 0);

        for(int i=0;i<trips.size();i++){
            timeline[trips[i][1]] += trips[i][0];
            timeline[trips[i][2]] -= trips[i][0];
        }

        int totalPassengers = 0;
        for(int i=0;i<1001;i++){
            totalPassengers += timeline[i];

            if(totalPassengers > capacity) return false; // pure line sweep

        /* Capacity = 9 ,, here max is 8 so acceptable
           4 ---------- 7
                5 ------------- 9
                                       10 ------ 17
           +4   +4+4.   4 (-4)  0 (-4)  +4        0 (-4)
           */

           // We dont need the internals to from , end cause we are removing at end of interval, so iff if the 1st interval not finish and second started no of Passengers increases.....
        }
        return true;
    }
};