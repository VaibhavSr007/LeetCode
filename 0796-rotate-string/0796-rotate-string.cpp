class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()){ return false;}
        if(s == goal){ return true;}
        int n = s.length();
        for(int i=0; i<n; i++){
            char st = s[0];
            s.erase(s.begin());
            s.push_back(st);
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};