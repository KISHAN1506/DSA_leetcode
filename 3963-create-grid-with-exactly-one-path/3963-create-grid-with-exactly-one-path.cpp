class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string r1 = "";
        for(int i = 0;i<n;i++){
            r1+=".";
        }
        ans.push_back(r1);
        r1 = "";
        for(int i = 0;i<n;i++){
            if(i == n-1){
                r1+=".";
            }else{
                r1+="#";
            }
        }

        for(int i = 1;i<m;i++){
            ans.push_back(r1);
        }
        return ans;
        
    }
};