class Solution {
public:
    bool isHappy(long n) {
        vector<long long> vals;
        vals.push_back(n);
        long long temp = n;
        while(true){
            long long sum = 0;
            while(temp != 0){
                long long digit = temp%10;
                sum += digit*digit;
                temp/=10;
            }
            vals.push_back(sum);
            if(sum == 1){
                return true;
            }
            temp = sum;
            for(long long i = 0;i<vals.size()-1;i++){
                if(vals[i] == temp){
                    return false;
                }
            }
        }
        return false;
    }
};