class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stt;
        int n = temp.size();
        vector<int> ans(n);

        for(int i = n-1;i>=0;i--){
            while(!stt.empty() && stt.top().first <= temp[i]){
                stt.pop();
            }

            if(stt.empty()){
                ans[i] = 0;
            }else{
                ans[i] = stt.top().second - i;
            }

            stt.push({temp[i],i});
        }
        return ans;
    }
};