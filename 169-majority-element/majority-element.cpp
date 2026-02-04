class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int majority = arr[0];
        int votes = 1;
        for(int i = 1;i<arr.size();i++){
            if(votes == 0){
                majority = arr[i];
                votes++;
            }else if(arr[i] == majority){
                votes++;
            }else {
                votes--;
            }
        }

        return majority;


    }
};