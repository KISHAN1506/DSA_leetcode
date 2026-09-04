class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n = arr.size();
        int ans=INT_MAX;
        for(int i = 0;i<n;i++){
            int maxVal = INT_MIN;
            int minVal = INT_MAX;

            for(int j = 0;j<=i;j++){
                maxVal = max(maxVal,arr[j]);
            }
            for(int j = i;j<n;j++){
                minVal = min(minVal,arr[j]);
            }
            if(maxVal-minVal <= k){
                return i;
            }
        }
        return -1;
    }
};