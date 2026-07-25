class MinStack {
    stack<pair<int,int>> s;
public:

    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()) s.push({value,value});
        else 
        {
            int mini = min(value,s.top().second);
            s.push({value,mini});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
