class Solution {
public:
    string sortSentence(string s) {
        string word = "";
        map<char,string> mp;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                mp[word.back()] = word;
                word = "";
            }
            else{
                word.push_back(s[i]);
            }
        }
        mp[word.back()] = word;
        
        word = "";
        for(auto i:mp){
            i.second.pop_back();
            word += i.second + " ";
        }
        word.pop_back();
        return word;
    }
};