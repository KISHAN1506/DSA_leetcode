class Solution {
public:
    int findMaxIdx(vector<vector<int>>& mat,int n,int m,int col){
        int maxValue = -1;
        int index = -1;

        for(int i = 0;i<n;i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = low + ((high - low)/2);
            int maxRowIdx = findMaxIdx(mat,n,m,mid);

            int left = mid-1 >=0 ? mat[maxRowIdx][mid-1] : -1;
            int right = mid+1 <m ? mat[maxRowIdx][mid+1] : -1;

            if(mat[maxRowIdx][mid]> left && mat[maxRowIdx][mid] > right){
                return {maxRowIdx,mid};
            }else if(mat[maxRowIdx][mid] < left){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return {-1,-1};

        // int maxVal = mat[0][0];
        // pair<int,int> idx = {0,0};
        // for(int i = 0;i<mat.size();i++){
        //     for(int j = 0;j<mat[0].size();j++){
        //         if(mat[i][j] > maxVal){
        //             maxVal = mat[i][j];
        //             idx = {i,j};
        //         }
        //     }
        // }
        // return {idx.first,idx.second};
    }
};