class Solution {
public:
    int noOfDays(vector<int>& weights, int wt){
        int days = 1;
        int load = 0;
        for(int i = 0;i<weights.size();i++){
            if(load + weights[i] <= wt){
                load += weights[i];
            }else{
                days++;
                load = weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int st = 0;
        int end = 0;

        for(auto& it:weights){
            if(it > st){
                st = it;
            }
            end += it;
        }

        while(st <= end){
            int mid = st + (end-st)/2;

            if (noOfDays(weights,mid) <= days){
                end = mid - 1;
            }else{
                st = mid + 1;
            }
        }
        return st;
    }
};