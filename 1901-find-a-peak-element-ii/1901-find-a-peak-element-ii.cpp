class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int maxVal = mat[0][0];
        pair<int,int> idx = {0,0};
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j] > maxVal){
                    maxVal = mat[i][j];
                    idx = {i,j};
                }
            }
        }
        return {idx.first,idx.second};
    }
};