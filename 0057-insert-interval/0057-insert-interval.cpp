class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        int n = arr.size();
        vector<vector<int>> res;
        int i = 0;
        // left part we just need to add directly
        while(i < n && arr[i][1] < newInterval[0]){
            res.push_back(arr[i]);
            i++;
        }

        // mid part
        while(i<n && arr[i][0] <= newInterval[1]){
            newInterval[0] = min(arr[i][0], newInterval[0]);
            newInterval[1] = max(arr[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // right part
        while(i<n){
            res.push_back(arr[i]);
            i++;
        }
        return res;


    }
};