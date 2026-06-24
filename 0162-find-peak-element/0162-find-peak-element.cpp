class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        if(n == 1){
            return 0;
        }
        if(n == 2){
            if(arr[0] > arr[1]){
                return 0;
            }
            return 1;
        }
        for(int i = 1;i<n-1;i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                return i;
            }
        }
        return arr[n-1]>arr[0] ? n-1 : 0;
    }
};