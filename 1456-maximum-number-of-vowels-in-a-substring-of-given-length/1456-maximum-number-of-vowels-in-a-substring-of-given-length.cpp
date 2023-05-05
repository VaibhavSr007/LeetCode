class Solution {
public:
    int maxVowels(string str, int k) {
        set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        int ans = 0;
        int i=0, j =0, cnt = 0;
        while(j<str.length()){
            if(j-i < k){
                if(s.find(str[j]) != s.end()){
                    cnt++;
                }
                j++;
            }
            else{
                if(s.find(str[j]) != s.end()){
                    cnt++;
                }
                if(s.find(str[i]) != s.end()){
                    cnt--;
                }
                i++;
                j++;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};