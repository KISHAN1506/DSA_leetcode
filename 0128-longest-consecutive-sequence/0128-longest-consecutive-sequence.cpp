class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        set<int> stt(nums.begin(),nums.end());

        int maxCnt = 1;
        int consi = 1;

        auto prev = stt.begin();
        auto curr = next(prev);


        while(curr != stt.end()){
            if(*prev + 1 == *curr){
                consi++;
            }else{
                consi = 1;
            }

            maxCnt = max(maxCnt,consi);
            prev++;
            curr++;
        }

        return maxCnt;

    }
};