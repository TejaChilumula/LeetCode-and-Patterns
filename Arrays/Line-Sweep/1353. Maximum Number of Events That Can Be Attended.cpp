class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        // Line Sweep + Greedy + Min Heap
        /*
            - You have to find the soonest ending event per day
            - so iterate through each day 1 to 100000 (constraint)
            - each day add any new events start at this day and attend the soonest ending event

             *** remove all the events which ended before cur day or expired , from heap
             For each day push all endday's of the events starting on this day.
             and then remove one more heap, means that attended on that particular day.

             An event started earlyyy but has a long end date will attend after all the short or
             sooner ended events before it. so that we can attend max events.
                1 --------------- 5
                1-1
                1----2
                1-------3
                     2 -------4

                so you will attend events that are ending soon on each day
                day - 1 - attend event 2
                day - 2 - attend event 3
                day - 3 - attend event 4
                day - 4.- attend event 5
                day - 5 - attend event 1

                In case of duplicates

                1 --------------- 5
                1-1
                1-1
                1----2
                1-------3
                     2 -------4

                you will attend event 2 on day - 1 and moves to day 2
                **** On day 2 we skipp all the events expired <2


             ****** IMPPPP AND REAL WORLD SIMULATION *****
             his is how real-world calendars, schedulers, and operating systems manage tasks:

                One task per time slot (like one event per day)

                Tasks have windows (start and end)

                You want to maximize throughput by choosing wisely

                📅 Think of:

                Calendar booking systems (Google Calendar, Outlook)

                Hospital appointment scheduling

                CPU task scheduling with deadlines

                College timetable generation

                Resource allocation in cloud computing


             
        */

        //*** The Basic Intution and the basic line sweep pattern wont work here ****
        // sort(events.begin(), events.end(), 
        // [](vector<int>& a, vector<int>&b){
        //     return a[0] < b[0];
        // });
        // map<int, int> mp;
        // int max_events_can_attend = 0, total = 0;

        // mp[events[0][0]]++;

        // for(int i=1;i<events.size();i++){
        //     if(events[i-1][0] != events[i][0]){
        //         mp[events[i][0]]++;
        //     }
        // }

        // for(auto [key, val] : mp){
        //     total+=val;
        //     max_events_can_attend = max(total, max_events_can_attend);
        // }
        // return max_events_can_attend;

        priority_queue<int, vector<int>, greater<int>> sooner_dates;
        sort(events.begin(), events.end());

        int day = 0, res =0, i=0;
        int n = events.size();

        // Why we need day and the i
        /*
            - Because day indicates the day and i indicates the index we are currently at in the events, cause while pushing all the events that are equal to start on the day, we dont need to come again from the start of the events instead from the cur index we iterate all the events.
            ****** At one day we can have multiple events starts
            so if we take the day as the index we might end up miss the duplicate events.....
        */

        while(i<n || !sooner_dates.empty()){

            if(sooner_dates.empty()) {day = events[i][0];}

            

            while(i<n && events[i][0] == day){
                    sooner_dates.push(events[i][1]);
                    i++;
            }

            while(!sooner_dates.empty() && sooner_dates.top() < day){
                sooner_dates.pop();
            }

            if(!sooner_dates.empty()){
                sooner_dates.pop();
                res++;
            }
            day++;
        }
        return res;
    }
};