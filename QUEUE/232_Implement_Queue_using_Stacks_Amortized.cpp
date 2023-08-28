class MyQueue {
public:

    // O(1) Push Operations
    // O(n) --> Pop Operations(in some cases) --> so O(1) amortized Time Complexity
    // O(n) --> Top Operations(in some cases) --> so O(1) amortized Time Complexity
    stack<int> input;
    stack<int> output;

    MyQueue() {
        
    }
    
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int result;
        if(!output.empty()){
            result = output.top();
            output.pop();
        }
        else {
            while(!input.empty()){
                 output.push(input.top());
                 input.pop();   
            }
            result = output.top();
            output.pop();
        }
        return result;
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else {
            while(!input.empty()){
                 output.push(input.top());
                 input.pop();   
            }
        }
        return output.top();  
    }
    
    bool empty() {
        return input.empty()&&output.empty();
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
