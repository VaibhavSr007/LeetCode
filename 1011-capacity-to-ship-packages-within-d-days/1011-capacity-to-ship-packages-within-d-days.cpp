class Solution {
public:
    // *** BOOK ALLOCATION PROBLEM *****
    
    bool is_possible(vector<int>& weights, int days, int mid){
    int student_count = 1;
    int page_count = 0;
    
    for(int i=0; i<weights.size(); i++){
        if(page_count + weights[i] <= mid){
            page_count += weights[i];
        }
        else{
            student_count++;
            if(student_count > days || weights[i] > mid){
                return false;
            }
            page_count = weights[i];
        }  
    }
    return true;
}
    
    int shipWithinDays(vector<int>& weights, int days) {
      
        int sum =0;
	    for(int i=0; i<weights.size(); i++){
            sum =  sum + weights[i];
        }
        
        int ans = -1;
        int s = 0;
        int e =  sum;
        int mid = s + (e-s)/2;
    
        while(s<=e){
            if(is_possible(weights,days,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s= mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};