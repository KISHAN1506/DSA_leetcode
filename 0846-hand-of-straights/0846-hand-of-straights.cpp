class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0){
            return false;
        }

        map<int,int> mpp;
        for(int& handNum : hand){
            mpp[handNum]++;
        }

        while(!mpp.empty()){
            int currNum = mpp.begin()->first;

            for(int i = 0;i<groupSize;i++){
                if(mpp[currNum + i] == 0){
                    return false;
                }
                mpp[currNum + i]--;
                if(mpp[currNum + i] < 1){
                    mpp.erase(currNum+i);
                }

            }
        }
        return true;
    }
};