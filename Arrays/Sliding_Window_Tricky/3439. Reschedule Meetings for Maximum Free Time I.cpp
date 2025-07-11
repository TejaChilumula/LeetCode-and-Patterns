You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.
Note that the meetings can not be rescheduled to a time outside the event.

Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]

Output: 2

Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].

// Simple Sliding window, no expanding, 
    /*
        - Take all the gaps in to vector
            - NOTE : 0 to startTime[0] and eventTime to endTime[n] is also a gap add these also the the spaces
        then add sapces to the sum
          and if the index > k then slide the wondow from the start++
    */


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int> spaces;
        int maxi = INT_MIN;
        int n = startTime.size();
        spaces.push_back(startTime[0] - 0);
        
        for(int i=1;i<n;i++){
            int space =startTime[i] - endTime[i-1];
            //if(spaces.size() == 0) spaces.push_back(space);
            spaces.push_back(space); 
        }
        spaces.push_back(eventTime - endTime[n-1]);

        int space_sum = 0, start = 0;
        for(int i=0;i<spaces.size();i++){
            space_sum += spaces[i];
            if(i - start + 1 > k+1)
                space_sum -= spaces[start++];

                maxi = max(maxi, space_sum);
        }

        return maxi;
        }
};