class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefMax(n);
        vector<int> suffMax(n);

        prefMax[0] = arr[0];
        suffMax[n-1] = arr[n-1];

        for(int i = 1;i<n;i++){
            prefMax[i] = max(prefMax[i-1],arr[i]);
        }

        for(int i = n-2;i>=0;i--){
            suffMax[i] = max(suffMax[i+1],arr[i]);
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            ans += min(prefMax[i],suffMax[i]) - arr[i];
        }
        return ans;

    }
};