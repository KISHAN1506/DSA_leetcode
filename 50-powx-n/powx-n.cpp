class Solution {
public:

    double soln(double x, long n){
        if(n == 0) return 1;
        if(n < 0){
            return 1/soln(x,n*-1);
        }

        if(n%2 == 0){
            return soln(x*x,n/2);
        }
        else {
            return x*soln(x*x,(n-1)/2);
        }
    }

    double myPow(double x, int n) {
        return soln(x,(long)n);
    }
};