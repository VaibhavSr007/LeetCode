class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long i = 1;  // min time taken can be 1 as min_time[i] * min_trip_time = 1*1 = 1
        long long j = 1e14;// max time taken can be 10^14 as max_time[i] * max_trip_time = 10^7 * 10^7 = 10^14
        
        // now we know our ans can lie b/w i and j only so we check what is the min time in which we
        // can do the tottal trips using binary search
        long long ans;
        while(i<=j){
            long long m = i + (j-i)/2;
            
            long long trips_done = 0;
            for(auto t:time){  // this will tell how many total trips are done if time m is taken
                trips_done += m/t; // [1,2,5]  m = 15, no. of 1 seconds trip can be done = 15/1 = 15
                                    // no. of 2 seconds trip can be done = 15/2  = 7
                                    // no. of 5 seconds trip can be done = 15/5 =  3 total = 25 trips
            }
            
            if(trips_done >= totalTrips){  // here if the trips done are greater or equal to what we
                ans = m;  // require than we save this "time" and check if lower than this is possible
                j = m-1;  // to chk lower than this we move end towards left 
            }
            else{   // if trips done are lower than what we need than we move i forward to reach
                i = m+1; // time where we do the required trips.
            }
        }
        
        return ans;
    }
};