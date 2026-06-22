class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(char it : text){
            mpp[it]++;
        }

        int cnt = 0;
        while(mpp['b']>=1 && mpp['a']>=1 && mpp['l']>=2 && mpp['o']>=2 && mpp['n']>=1){
            cnt++;
            mpp['b']--;
            mpp['a']--;
            mpp['l']--;
            mpp['l']--;
            mpp['o']--;
            mpp['o']--;
            mpp['n']--;
        }
        return cnt;
    }
};