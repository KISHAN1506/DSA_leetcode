class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long threshold = 1000;

        while(threshold <= n){
            commas += n-threshold+1;
            threshold *= 1000;
        }

        return commas;
    }
};