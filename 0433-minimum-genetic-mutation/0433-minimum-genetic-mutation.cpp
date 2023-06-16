class Solution {
public:
    int minMutation(string st, string en, vector<string>& bank) {
        set<string> s, vis;
        int n= st.length();
        vector<char> d = {'A', 'T', 'G', 'C'};
        for(auto i:bank){
            s.insert(i);
        }
        queue<string> q;
        
        int cnt = 0;
        q.push(st);
        while(!q.empty()){
        
            int size = q.size();
            
            for(int i=0; i<size; i++){
                string temp = q.front();
                // cout<<temp<<" ";.
                q.pop();
                if(temp==en){
                    return cnt;
                }
                for(int k=0; k<8; k++){
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
            cnt++;
        }
        cout<<endl;
        
        return -1;
    }
};