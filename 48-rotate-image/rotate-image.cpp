class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i =0;i<=n-1;i++){
            for(int j = i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }

        // Why to traverse 2nd half of matrix if not needed
        // for(int i =0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         if(i != j && i > j){
        //             swap(matrix[i][j], matrix[j][i]);
        //         }
        //     }
        // }

        


        // Bruteforce method and ignore the fact inplace
        // int n = matrix.size();

        // vector<vector<int>> ans(n,vector<int>(n));

        // int k = n-1;
        // int l = 0;
        // while(k>=0){
        //     for(int i = 0;i<n;i++){
        //         ans[i][k] = matrix[l][i];
        //     }
        //     k--;
        //     l++;
        // }

        // for(int i = 0;i<n;i++){
        //     for(int j = 0;j<n;j++){
        //         matrix[i][j] = ans[i][j];
        //     }
        // }

    }
};