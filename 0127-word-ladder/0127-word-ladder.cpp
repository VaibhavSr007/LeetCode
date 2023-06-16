class Solution {
public:
    int ladderLength(string st, string en, vector<string>& word) {
        set<string> s, vis;
        int n= st.length();
        vector<char> d;
        
        for(int i='a'; i<='z'; i++){
            d.push_back(char(i));
        }
        for(auto i:word){
            s.insert(i);
        }
        
        queue<string> q;
        int cnt = 0;
        q.push(st);
        
        while(!q.empty()){
            cnt++;
            int size = q.size();
            for(int i=0; i<size; i++){
                string temp = q.front();
                q.pop();
                
                if(temp==en){
                    return cnt;
                }
                
                for(int k=0; k<temp.length(); k++){
                    string copy = temp;
                    for(auto j:d){
                        copy[k] = j;
                        // cout<<copy<<" ";
                        if(s.find(copy) != s.end() && vis.find(copy) == vis.end()){
                            vis.insert(copy);
                            q.push(copy);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};