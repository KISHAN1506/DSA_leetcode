class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2){
        return v1[1] < v2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int count = 1;
        int last = pairs[0][1];
        for(int i = 1;i<pairs.size();i++){
            if(last < pairs[i][0]){
                count++;
                last = pairs[i][1];
            }
        }
        return count;
    }
};