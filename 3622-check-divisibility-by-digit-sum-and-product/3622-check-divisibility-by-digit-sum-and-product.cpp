class Solution {
public:
    int sumDigAndProd(int num){
        int sum = 0;
        int prod = 1;
        while(num > 0){
            int digit = num%10;
            sum += digit;
            prod *= digit;
            num /= 10;
        }
        return sum+prod;
    }
    
    bool checkDivisibility(int n) {
        return n%sumDigAndProd(n) == 0;
    }
};