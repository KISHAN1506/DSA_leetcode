class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> stt(nums.begin(),nums.end());

        int val = k;
        while(true){
            if(stt.find(val) == stt.end()){
                return val;
            }
            val+=k;
        }
        return 0;
    }
};