class Solution {
public:
    
   void merge(vector<int>& v, int s, int e){
    int m = s+(e-s)/2;
    
    int len1 = m-s+1;
    int len2 = e-m;
    
    vector<int> v1(len1);
    vector<int> v2(len2);
 
 // copying the halves of main array into v1 v2 small arrays
    int idx = s;
    for(int i=0; i<len1; i++){
        v1[i] = v[idx++];
    }
    
    idx = m+1;
    for(int i=0; i<len2; i++){
        v2[i] = v[idx++];
    }

//  merging the sorted arrays
    int idx1 = 0;
    int idx2 = 0;
    idx = s;
    
    while(idx1<len1 && idx2<len2){
        if(v1[idx1]<v2[idx2]){
            v[idx++] = v1[idx1++];
        }
        else{
            v[idx++] = v2[idx2++];
        }
    }
    while(idx1<len1){
        v[idx++] = v1[idx1++];
    }
    while(idx2<len2){
        v[idx++] = v2[idx2++];
    }
}

void merge_sort(vector<int>& v, int s, int e){
    if(s>=e){
        return ;
    }
    
    int m = s + (e-s)/2;
// two seprated part for sorting
    merge_sort(v,s,m);
    merge_sort(v,m+1,e);
//now nerging both sorted parts   
    merge(v,s,e);
}
    vector<int> sortArray(vector<int>& nums) {
        
        // for(int i=0; i<nums.size()-1; i++){
        //     for(int j=i+1; j<nums.size(); j++){  selection sort
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        
        // for(int j=0; j<nums.size(); j++){
        //     for(int i=0; i<nums.size()-1; i++){
        //         if(nums[i]>nums[i+1]){
        //             swap(nums[i],nums[i+1]);         //bubble sort
        //         }
        //     }
        // }
        
        // for(int i=1; i<nums.size(); i++){
        //     for(int j=nums.size()-1; j>=0; j--){ 
        //         if(nums[j]>nums[j+1]){              insertion remaining
        //             swap(nums[j],nums[j+1]);
        //         }  
        //     }
        // }
        
        merge_sort(nums,0,nums.size()-1);    // using merge sort
        
        return nums; 
    }
};