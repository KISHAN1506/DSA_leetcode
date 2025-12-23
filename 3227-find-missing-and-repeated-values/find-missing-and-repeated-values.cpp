class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n*n;
        vector<int> hash(total + 1,0);
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid.size();j++){
                hash[grid[i][j]]++;
            }
        }
        int noOcc,twiceOcc;
        for(int i = 0;i<hash.size();i++){
            if(hash[i] == 0){
                noOcc = i;
            }else if(hash[i] == 2){
                twiceOcc = i;
            }
        }
        return {twiceOcc,noOcc};
        // ENDED
    }
};