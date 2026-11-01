class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(),nums.end());
        int cnt = 0;

        for(int i = 0;i<nums.size();i++){
            cnt += (nums[i] - minVal);
        }
        return cnt;
    }
};