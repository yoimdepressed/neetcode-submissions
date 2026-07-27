class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    void addNum(int num) {
        if(min_heap.size()>0 && num > min_heap.top())
        {
            min_heap.push(num);
            if(min_heap.size() - max_heap.size() > 1)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
        else
        {
            max_heap.push(num);
            if(max_heap.size() - min_heap.size() > 1)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if((min_heap.size() + max_heap.size()) % 2 == 1)
        {
            if(max_heap.size() > min_heap.size())
                return (double)max_heap.top();
            return (double)min_heap.top();
        }
        else
        {
            return (double)(min_heap.top()+max_heap.top())/2.0;
        }
    }
};
