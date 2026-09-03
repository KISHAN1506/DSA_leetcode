class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCnt = 0;
        int n = nums1.size();
        int smOdd = INT_MAX;
        int smEven = INT_MAX;
        for(auto& it : nums1){
            if(it % 2 == 1){
                oddCnt++;
                smOdd = min(smOdd,it);
            }else{
                smEven = min(smEven,it);
            }
        }

        int evenCnt = n-oddCnt;

        if(oddCnt == 0 || oddCnt == n){
            return true;
        }

        if(smEven > smOdd){
            return true;
        }
        return false;
    }
};