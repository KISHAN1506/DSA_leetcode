class Solution {
public:
    int valProd(int n){
        int temp = 1;
        while(n > 0){
            int digit = n%10;
            temp *= digit;
            n /= 10;
        }
        return temp;
    }
    int smallestNumber(int n, int t) {
        int val = n;
        while(true){
            if(valProd(val) % t == 0) return val;
            val++;
        }
    }
};