class Solution {
public:
    int furthestBuilding(vector<int>& nums, int bricks, int ladders) {
        int ans = 0;
        priority_queue<int> pq;
        
        int i=0;
        for(i=0; i<nums.size()-1; i++){
            if(nums[i+1]-nums[i] > 0){
                
                bricks -= (nums[i+1]-nums[i]);
                pq.push(nums[i+1]-nums[i]);
                
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
                
                if(ladders < 0){
                    break;
                }
            }
        }
        return i;
    }
};