class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int sumVal = 0;
        int n = nums.size();
        for (int start = 0; start < n; start++){
            sumVal += nums[start];
            if (sumVal > maxVal){
                maxVal = sumVal;
            }

            // We are doing this because is sumVal of a subarray is -ve
            // It is anyhow going to decrease the total value, so we won't add next coming value in 
            if (sumVal < 0){
                sumVal = 0;
            }
        }
        return maxVal;

        // BRUTEFORCE APPROACH
        // int val = INT_MIN;
        // int n = nums.size();
        // for(int start = 0;start<n;start++){
        //     for(int end = start;end<n;end++){
        //         int sumval = 0;
        //         for(int k = start;k<=end;k++){
        //             sumval += nums[k];
        //         }
        //         if(sumval > val){
        //             val = sumval;
        //         }
        //      }
        // }
        // return val;
        
    }
};