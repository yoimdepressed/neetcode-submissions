class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size() - 1;
        int col = matrix[0].size();
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target) right = mid - 1;
            else if(matrix[mid][0] < target)
            {
                if(matrix[mid][col-1] == target) return true;
                else if(matrix[mid][col-1] > target)
                {
                    int l = 0;
                    int r = col - 1;
                    while(l <= r)
                    {
                        int m = (l + r) / 2;
                        if(matrix[mid][m] == target) return true;
                        else if(matrix[mid][m] > target) r = m - 1;
                        else l = m + 1;
                    }
                    return false;
                }
                else left = mid + 1;
            }
        }
        return false;
    }
};
