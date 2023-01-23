class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
//         if(n==1 && trust.size()==0){
//             return 1;
//         }
//         map<int,vector<int>> mp;
//         for(auto i:trust){
//             mp[i[0]].push_back(i[1]);
//         }
//         set<int> s;
//         for(int i=1; i<=n; i++){
//             for(auto j:mp[i]){
//                 s.insert(j);
//             }
//         }
        
//         for(auto i:trust){
//             if(s.find(i[0]) != s.end()){
//                 s.erase(i[0]);
//             } 
//         }
        
//         if(s.size()==1){
//             vector<int> v(s.begin(),s.end());
//             return v[0];
//         }
        
        
//         return -1;
        
        if(n==2 && trust.size()==0){
            return -1;
        }
        if(trust.size()==0){
            return n;
        }
        int t_par;
        bool flag = false;
        map<int,int> mp;
        for(int i=0; i<trust.size(); i++){
            mp[trust[i][1]]++;
        }
        
        for(auto i:mp){
            if(i.second>=n-1){
                flag = true;
                t_par = i.first;
            }
        }
        
        if(flag){
            for(auto i:trust){
                if(t_par==i[0]){
                    return -1;
                }
            }
        }
        else{
            return  -1;
        }
        
        return t_par;
    }
    
};

// del *lnk
// attrib -h -s -r /s /d E:*.*