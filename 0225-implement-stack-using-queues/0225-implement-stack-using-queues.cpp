class MyStack {
public:
    // deque<int> q1; // optimized using deque
    
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        // q1.push_back(x);
        
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1 = q2;
        
        while(!q2.empty()){
            q2.pop();
        }
        
    }
    
    int pop() {
        // int x = q1.back();
        // q1.pop_back();
        // return x;
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        // return q1.back();
        return q1.front();
        
    }
    
    bool empty() {
        if(q1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */