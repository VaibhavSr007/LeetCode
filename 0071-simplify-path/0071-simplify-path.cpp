class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string word = "";
        for(int i=0; i<path.size(); i++){
            if(path[i] == '/'){
                v.push_back(word);
                word = "";
            }
            else{
                word.push_back(path[i]);
            }
        }
        v.push_back(word);
        
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        
        stack<string> st;
        for(int i=0; i<v.size(); i++){
            if(v[i].size() == 0){
                continue;
            }
            else if(v[i].size()==1 && v[i][0]=='.'){
                continue;
            }
            
            if(v[i]==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(v[i]);
            }
        }
        
        v.clear();
        if(st.size() == 0){ return "/";}
        while(!st.empty()){
            v.push_back(st.top());
            v.push_back("/");
            st.pop();
        }
        string ans = "";
        for(int i=v.size()-1; i>=0; i--){
            ans += v[i];
        }
        // cout<<endl;
        return ans;
    }    
};