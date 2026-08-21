class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> stt;
        stt.reserve(nums.size() * 2);
        for(auto& x : nums){
            stt.insert(x);
        }
        int n = nums.size();
        int maxCnt = 0;

        for(auto& x : stt){
            if(stt.find(x - 1) == stt.end()){
                int consi = 1;
                int temp = x;
                while(stt.find(temp+1) != stt.end()){
                    consi++;
                    temp++;
                }
                maxCnt = max(maxCnt,consi);
            }   
        }
        return maxCnt;
    }
};