class Solution {
public:
    int firstStableIndex(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> maxPref(n),minSuff(n);

        maxPref[0] = arr[0];
        for(int i = 1;i<n;i++){
            maxPref[i] = max(maxPref[i-1],arr[i]);
        }
        
        minSuff[n-1] = arr[n-1];
        for(int i = n-2;i>=0;i--){
            minSuff[i] = min(minSuff[i+1],arr[i]);
        }

        for(int i = 0;i<n;i++){
            if(maxPref[i] - minSuff[i] <= k){
                return i;
            }
        }
        return -1;
            
    }
};