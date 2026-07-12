class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> arrTemp = arr;
        sort(arrTemp.begin(),arrTemp.end());
        map<int,int> mpp;
        int rank = 1;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            if(!mpp[arrTemp[i]]){
                mpp[arrTemp[i]] = rank++;
            }
        }

        vector<int> ans;
        for(int i = 0;i<n;i++){
            ans.push_back(mpp[arr[i]]);
        }

        return ans;
    }
};