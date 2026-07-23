class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int i = 0;
        int j = n - 1;
        int count = 0;
        while (i <= j) {
            int tot = people[i] + people[j];
            if (tot > limit) {
                j--;
                count++;
            } else{
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
    // int numRescueBoats(vector<int>& arr, int limit) {
    //     return 0;
        // int val = 0;
        // int sum = 0;
        // int n = arr.size();
        // for(auto &it:nums){
        //     sum += it;
        // }

        // sort(arr.begin(),arr.end());
        // if(n == 1) return 1;
        // int i = 0;
        // int j = 1;

        // int boat = 0;
        // while(i < n && j < n){
        //     if(arr[i] + arr[j] <= limit){
        //         boat++;
        //         i+=2;
        //         j+=2;
        //     }else{
        //         boat += 2;
        //         i+=2;
        //         j+=2;
        //     }
        // }

        // if(i == n-1){
        //     boat++;
        // }

        // return boat;
    // }
};