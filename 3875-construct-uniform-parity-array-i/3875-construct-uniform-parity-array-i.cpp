class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCnt = 0;
        int n = nums1.size();
        for(auto& it: nums1){
            if(it % 2 == 1){
                oddCnt++;
            }
        }
        int evenCnt = n-oddCnt;

        if(oddCnt == n || evenCnt == n){
            return true;
        }

        if(oddCnt >= 1){
            return true;
        }
        return false;
    }
};