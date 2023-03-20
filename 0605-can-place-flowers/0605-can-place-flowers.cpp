class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        
        while(i<flowerbed.size()){
            if(flowerbed[i] == 0){
                if(i-1>=0 && flowerbed[i-1]==0){
                    if(i+1<flowerbed.size() && flowerbed[i+1]==0){
                        n--;
                        i+=2;
                    }
                    else if(i+1 >= flowerbed.size()){
                        n--;
                        i+=2;
                    }
                    else{
                        i+=1;
                    }
                }
                else if(i-1 < 0){
                    if(i+1<flowerbed.size() && flowerbed[i+1]==0){
                        n--;
                        i+=2;
                    } 
                    else if(i+1 >= flowerbed.size()){
                        n--;
                        i+=2;
                    }
                    else{
                        i+=2;
                    }
                }
                else{
                    i+=1;
                }
            }
            else{
                i+=2;
            }
            
            if(i >= flowerbed.size()){
                break;
            }
        }
        
        if(n>0){
            return false;
        }
        return true;
    }
};