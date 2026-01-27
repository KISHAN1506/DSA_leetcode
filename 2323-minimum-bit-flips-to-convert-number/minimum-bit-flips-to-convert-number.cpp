class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        
        int cnt = 0;
        int temp = ans;
        while(temp != 0){
            if(temp%2 == 1){
                cnt++;
            }
            temp/=2;
        }
        return cnt;
    }
};