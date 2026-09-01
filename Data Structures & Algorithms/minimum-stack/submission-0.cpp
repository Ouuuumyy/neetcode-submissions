class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        mainStack.push(value);
        if(minStack.empty())
            minStack.push(value);
        else
        {
            int tmp = minStack.top();
            if(tmp < value)
                minStack.push(tmp);
            else
                minStack.push(value);
        }
    }
    
    void pop() {
        minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
