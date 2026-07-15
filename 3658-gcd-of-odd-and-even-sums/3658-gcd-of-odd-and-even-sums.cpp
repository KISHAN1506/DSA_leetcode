class Solution {
public:
    int gcdCal(int a,int b){
        // gcd(a,b) == gcd(a%b,b);
        while(a>0 && b>0){
            if(a>b) a = a%b;
            else b = b%a;
        }
        return (a==0)? b : a;
    }

    int gcdOfOddEvenSums(int n) {
        int oddSum = 0;
        int evenSum = 0;

        for(int i = 0;i<=2*n;i++){
            if(i%2 == 0) evenSum += i;
            else oddSum += i;
        }

        return gcdCal(oddSum,evenSum);
    }
};