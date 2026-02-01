class Solution {
public:
    long long M = 1000000007;
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = (n)/2;

        long long result = (pow((long long)5,even)*pow((long long)4,odd))%M;
        return result;
    }

    long long pow(long long a,long long b){
        if(b == 0) return 1;
        if(b<0){
            return (1/((pow(a,-1*b))%M))%M;
        }

        if(b%2 == 0){
            return pow((a*a)%M,b/2);
        }else{
            return (a*(pow(a,b-1))%M)%M;
        }
    }
};