class MyStack {
    int stack[101];
    int t;
public:
    MyStack() {
        t = -1;
    }
    
    void push(int x) {
        stack[++t] = x;
    }
    
    int pop() {
        return stack[t--];
    }
    
    int top() {
        return stack[t];
    }
    
    bool empty() {
        return t < 0;
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