#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // line sweep , we only care abou the start and end

        // TRICK ---- Here we wont deduct at end, instead we add till end
            // ----- So, **** we deduct after end, i.e end+1

            vector<int> flights(n+1,0);

            for(int i=0;i<bookings.size();i++){
                int booking_seats_from = bookings[i][0]-1;
                int booking_seats_to = bookings[i][1]; // we can deduct at this

                flights[booking_seats_from] += bookings[i][2];
                flights[booking_seats_to] -= bookings[i][2];

            }

            // till above we only summed up the to and from's but interiors we need to take care, so wee need to sum up so interiors will be added to each level and reduces as well, upon the booking finishes
            int total_bookings = 0;
            for(int i=0;i<=n;i++){
                total_bookings += flights[i];
                flights[i] = total_bookings;
            }
        
        flights.pop_back();
        return flights;
    }
};