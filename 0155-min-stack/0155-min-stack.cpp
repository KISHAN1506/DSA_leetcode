class MinStack {
public:
    stack<pair<int,int>> stt;
    MinStack() {
    }
    
    void push(int value) {
        if(stt.empty()){
            stt.push({value,value});
            return;
        }
        stt.push({value,min(stt.top().second,value)});
    }
    
    void pop() {
        stt.pop();
    }
    
    int top() {
        return stt.top().first;
    }
    
    int getMin() {
        return stt.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */