class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digitLow = floor(log10(low)) + 1;
        int digitHigh = floor(log10(high)) + 1;
        vector<int> ans;

        for(int digit = digitLow;digit<=digitHigh;digit++){
            for(int start = 1;start<=9;start++){
                if(start+digit > 10){
                    break;
                }
                int num = start;
                int prev = start;

                for(int i = 0;i<digit-1;i++){
                    num = num*10;
                    prev++;
                    num += prev;

                }
                if(num>=low && num<=high){
                    ans.push_back(num);
                }
            }
        }
        return ans;

    }
};