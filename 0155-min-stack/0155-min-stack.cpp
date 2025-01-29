class MinStack {
public:
    stack<int> st;
    stack<int> minSeen;
    MinStack() {
        // stack<int> st;
        // stack<int> minSeen;
    }
    
    void push(int val) {
        st.push(val);

        if(minSeen.empty()){
            minSeen.push(val);
        } else {
            if(minSeen.top() > val) {
                minSeen.push(val);
            } else {
                minSeen.push(minSeen.top());
            }
        }
    }
    
    void pop() {
        st.pop();
        minSeen.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSeen.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */