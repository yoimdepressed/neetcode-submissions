class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0; // Changed to int, renamed for clarity
        int n = heights.size();
        
        stack<int> nextse; 
        vector<int> arr1(n, n); 
        
        stack<int> prevse; 
        vector<int> arr2(n, -1); 
        
        // 1. Find Next Smaller Element (NSE)
        for(int i = 0; i < n; i++) {
            while(!nextse.empty() && heights[i] < heights[nextse.top()]) {
                arr1[nextse.top()] = i;
                nextse.pop();
            }
            nextse.push(i);
        }
        
        // 2. Find Previous Smaller Element (PSE)
        for(int i = n - 1; i >= 0; i--) {
            while(!prevse.empty() && heights[i] <= heights[prevse.top()]) {
                arr2[prevse.top()] = i;
                prevse.pop();
            }
            prevse.push(i);
        }
        
        // 3. Calculate Area
        for(int i = 0; i < n; i++) {
            // Width is just the distance between the right and left bounds
            int width = arr1[i] - arr2[i] - 1;
            int area = width * heights[i];
            
            // max() now works perfectly because both are 'int'
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};
