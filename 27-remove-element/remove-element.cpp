class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        int end = nums.size() - 1;

        int ctr = nums.size();
        while(start<=end){
            if(nums[start] == val){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end]= temp;
                end--;ctr--;
            }else{
                start++;
            }
        }
        return ctr;
    }
};