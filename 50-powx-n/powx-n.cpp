class Solution {
public:
    double myPow(double x, int n) {
        // double ans = 1;
        // if(n >= 0){
        //     for(double i = 0;i<n/2;i++){
        //         ans*=x;
        //         ans*=ans;
        //     }
        //     return ans;
        // }

        // for(double i = 0;i<-n/2;i++){
        //     ans/=x;
        //     ans*=ans;
        // }
        return pow(x,n);

    }
};