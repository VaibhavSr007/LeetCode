class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            
            if(!st.empty()){
                
                if(st.top() > 0 && nums[i] < 0){
                    
                    bool chk = true;
                    while(!st.empty() && (st.top() > 0 && nums[i] < 0)){
                        if(st.top() < abs(nums[i])){
                            st.pop();
                        }
                        else if(st.top() > abs(nums[i])){
                            chk = false;
                            break;
                        }
                        else if(st.top() == abs(nums[i])){
                            st.pop();
                            chk = false;
                            break;
                        }
                    }
                    
                    if(chk){
                        st.push(nums[i]);
                    }
                }
                else{
                    st.push(nums[i]);
                }
            }
            
            else{
                st.push(nums[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};