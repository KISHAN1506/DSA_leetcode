class Solution {
public:
    bool isUgly(int n) {

        if(n<=0) return false;

        while(n%2 == 0){
            n /= 2;
        }
        while(n%3 == 0){
            n /= 3;
        }
        while(n%5 == 0){
            n /= 5;
        }

        return (n == 1);

        // if(n == 1){
        //     return true;
        // }
        // vector<int> gcds;

        // for(long i = 1;i*i<n;i++){
        //     if(n % i == 0){
        //         gcds.push_back(i);
        //     }if(n %  == 0 && n!=){
        //         gcds.push_back(n-i)
        //     }
        // }

        // for(int i = 0;i<gcds.size();i++){
        //     if(gcds[i] != 2 && gcds[i] != 3 || gcds[i] != 5 ){
        //         return true;
        //     }
        // }
        // return false;
    }
};