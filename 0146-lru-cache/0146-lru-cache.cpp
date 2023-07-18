class LRUCache {
public:
    
    class dll{
        public:
            dll *next;
            dll *prev;
            int key;
            int val;

            dll(int k, int v){
                key = k;
                val = v;
            }
    };
    
    int size;
    dll *head = new dll(-1, -1);
    dll *tail = new dll(-1, -1);
    map<int, dll*> mp;
    
    void add(dll* &toadd){
        toadd->prev = tail->prev;
        tail->prev->next = toadd;
        tail->prev = toadd;
        toadd->next = tail;  
    }
    
    void del(dll* &todel){
        dll *todelprev = todel->prev;
        dll *todelnext = todel->next;
        todelprev->next = todelnext;
        todelnext->prev = todelprev;
    }
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            dll *node = mp[key];
            int val = mp[key]->val;
            del(node);
            add(node);
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){
            dll *node = mp[key];
            mp[key]->val = value;
            del(node);
            add(node);
        }
        else{
            if(mp.size() == size){
                mp.erase(head->next->key);
                del(head->next);
            }
            dll *added = new dll(key, value);
            add(added);
            mp[key] = added;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
    
    
//     map<int,int> mp;
//     deque<int> q;
//     int size;
    
//     LRUCache(int capacity) {
//         size = capacity;
//     }
    
//     void erase(deque<int> &q, int k){
//         vector<int> v;
//         while(q.front() != k){
//             v.push_back(q.front());
//             q.pop_front();
//         }
        
//         q.pop_front();
//         for(int i=v.size()-1; i>=0; i--){
//             q.push_front(v[i]);
//         }
//     }
    
//     int get(int key) {
//         if(mp.find(key) != mp.end()){
//             erase(q, key);
//             q.push_back(key);
//             return mp[key];
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
        
//         if(mp.find(key) != mp.end()){
//             erase(q, key);
//         }
//         if(q.size() == size){
//             int oldkey = q.front();
//             q.pop_front();
//             mp.erase(oldkey);
//         }
//         q.push_back(key);
//         mp[key] = value;
//     }