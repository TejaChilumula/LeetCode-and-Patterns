class MyCalendar {
public:
    /*
        - Using Line Sweep

        ******** At any interval if we get count as 2, means this start or end
            overlapped before exiting the already existed events *********

         - But bit tricky
            - 2 Cases !!!!
             CASE - 1:
              
               start overlaps with the existing meetings

                +1 .     -1               +1          -1
               10 ----- 20               44 -------- 50
                    15 -------- 25 ( Start overlapping )
                    +1
                    total = 2
            CASE - 2:
                end overlaps with the exisitng meetings
                +1        -1               +1         -1
                10 ----- 20               44 -------- 50
                                35 ------------- 47 ( end overlapping )
                                +1               -1
                                          total = 2  means overlap
    */
    map<int, int> events_starts_ends;
    int total;
    MyCalendar() {
        total = 0;
    }
    
    bool book(int start, int end) {
        total = 0;
        events_starts_ends[start]++;
        events_starts_ends[end]--;

        for(auto [key, val] : events_starts_ends){
            total += val;
            if(total > 1){
            events_starts_ends[start]--;;
            events_starts_ends[end]++;;
            return false;
        }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */