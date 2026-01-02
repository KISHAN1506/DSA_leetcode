class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(log(n+m))
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m*n - 1;
        while(low<=high){
            int mid = low +((high-low)/2);
            int val = matrix[mid/n][mid%n];

            if(val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
            


        // O(n+m)
        // int n = matrix.size();
        // int m = matrix[0].size();

        // int i = 0;
        // int j = m-1;

        // while(i < n && j>=0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }else if(matrix[i][j] > target){
        //         j--;
        //     }else {
        //         i++;
        //     }
        // }

        return false;
    }
};