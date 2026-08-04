class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = 1e9;
        int maxVal = -1e9;

        for(auto& it : nums){
            if(it > maxVal){
                maxVal = it;
            }
            if(it < minVal){
                minVal = it;
            }
        }

        map<int,int> mpp;
        for(int i = minVal;i<=maxVal;i++){
            mpp[i]++;
        }

        for(auto& it : nums){
            mpp[it]--;
            if(mpp[it] == 0){
                mpp.erase(it);
            }
        }

        vector<int> ans;
        for(auto& it : mpp){
            ans.push_back(it.first);
        }
        return ans;
    }
};