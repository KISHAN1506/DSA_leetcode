class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }

    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int val = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return val;

        // Issue here is 2 more stacks
        // stack<int> temp = s1;
        // stack<int> rev;
        // while(!temp.empty()){
        //     rev.push(temp.top());
        //     temp.pop();
        // }
        // return rev.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */