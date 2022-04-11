//Time: 80 ms (10.22%), Space: 17.1 MB (6.77%) - LeetHub

class MinStack {
    int stack[30000];
    int t;
public:
    MinStack() {
        t = -1;
    }
    
    void push(int val) {
        stack[++t] = val;
    }
    
    void pop() {
        --t;
    }
    
    int top() {
        return stack[t];
    }
    
    int getMin() {
        int Min = INT_MAX;
        for(int i = 0; i <= t; i++) 
            Min = min(Min, stack[i]);
        return Min;
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
