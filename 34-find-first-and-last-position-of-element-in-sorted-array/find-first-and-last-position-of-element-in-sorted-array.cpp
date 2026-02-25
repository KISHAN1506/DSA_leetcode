class Solution {
public:
    int firstPosition(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int lastPosition(vector<int>& nums, int target){
        int st = 0;
        int end = nums.size()-1;
        int ans = -1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                ans = mid;
                st = mid+1;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        return {firstPosition(nums,target),lastPosition(nums,target)};


        // This approach has a fatal flaw I realized, I was trying to find the 1st pos then iterate ,but what if array is
        // [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2] --> will go till O(n)
        // int st = 0;
        // int end = nums.size() - 1;

        // int sans = 0;
        // int eans = 0;
        // int idx = -1;
        // while(st <= end){
        //     int mid = st + (end-si)/2;
        //     if(nums[mid] == target){
        //         idx = mid;
        //         break;
        //     }

        //     if(nums[mid]<=)
        // }
    }
};