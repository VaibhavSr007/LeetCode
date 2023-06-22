class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        bool chk = false;
        bool ans1 = true, ans2 = true;
        vector<int> nums1(nums);
        vector<int> nums2(nums);
        for(int i=1; i<nums1.size(); i++){
            if(nums1[i-1] > nums1[i]){
                if(!chk){
                    chk = true;
                    nums1[i-1] = nums1[i];
                }
                else{
                    ans1 = false;
                    break;
                }
            }
        }

        for(int i=1; i<nums1.size(); i++){
            cout<<nums1[i]<<" ";
            if(nums1[i-1] > nums1[i]){
                ans1 = false;
            }
        }
        cout<<endl;

        chk = false;
        for(int i=nums2.size()-2; i>=0; i--){
            if(nums2[i+1] < nums2[i]){
                if(!chk){
                    chk = true;
                    nums2[i+1] = nums2[i];
                }
                else{
                    ans2 = false;
                }
            }
        }

        for(int i=nums2.size()-2; i>=0; i--){
            cout<<nums2[i+1]<<" ";
            if(nums2[i+1] < nums2[i]){
                ans2 = false;
            }
        }

        if(ans1 || ans2){
            return true;
        }

        return false;
    }
};