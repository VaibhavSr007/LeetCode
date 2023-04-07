using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         // vector<int> a;
//         for(int i=0; i<n; i++){
//             nums1.pop_back();
//         }
        
//         for(int j=0; j<n; j++){
//             nums1.push_back(nums2[j]);
//         }
        
//         // nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        
//         sort(nums1.begin(),nums1.end());
//         // cout<<a;
        
//         vector<int> v(m+n);
//         int idx = 0;
//         int idx1 = 0;
//         int idx2 = 0;
        
//         while(idx1<m && idx2<n){
//             if(nums1[idx1]<nums2[idx2]){
//                 v[idx++] = nums1[idx1++];
//             }
//             else{
//                 v[idx++] = nums2[idx2++];
//             }
//         }
        
//         while(idx1<m){
//             v[idx++] = nums1[idx1++];
//         }
        
//         while(idx2<n){
//             v[idx++] = nums2[idx2++];
//         }
        
//         nums1 = v;
        
        for(int i=0; i<n; i++){
            nums1.pop_back();
        }
        
        int i=0, j=0;
        while(i< nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
            }
        }
        
        while(j<nums2.size()){
            nums1.push_back(nums2[j]);
            j++;
        }
        
        // return  nums1;
    }
};