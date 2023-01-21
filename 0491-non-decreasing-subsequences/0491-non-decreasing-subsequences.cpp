class Solution {
public:
//    void find(int idx,int n,vector<int>& nums,vector<int>& ds,set<vector<int>>& ans)
//     {
//         // out of bound
//         if(idx>=n)
//         {
//             // check i am having my subsequence length more than 1 or not
//             if(ds.size()>=2) ans.insert(ds);
//             return;
//         }
        
//         // if i am having somehitng in my ds so check my curr idx val is greater or equal to prev or not
//         // if my ds is empty then also put curr idx val into it
//         if(!ds.size() || ds.back()<=nums[idx])
//         {
//             ds.push_back(nums[idx]);
//             find(idx+1,n,nums,ds,ans);
//             ds.pop_back();
//         }
        
//         // above conditions are not satisfied, skip curr value
//         find(idx+1,n,nums,ds,ans);
//     }
    
    void solve(vector<int>& temp, vector<int>& nums, set<vector<int>>& s, int idx){
        if(idx>=nums.size()){
            if(temp.size()>=2){
                s.insert(temp);
            }
            return ;
        }
        
        if(temp.size()==0 || temp[temp.size()-1]<=nums[idx]){ // if the temp is empty or when back of
            temp.push_back(nums[idx]);  // temp is less than nums[idx] than we push and call recursion
            solve(temp,nums,s,idx+1);
            temp.pop_back();         // this is backtracking
        }
        solve(temp,nums,s,idx+1);  // later we make call recursion without including nums[idx]
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums){
        
        set<vector<int>> s;
        vector<int> temp;
        solve(temp,nums,s,0);
        
        return vector(s.begin(),s.end());
        // return ans;
    }
};