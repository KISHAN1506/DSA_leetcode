class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q = queries.size();
        int m = logs.size();

        sort(logs.begin(),logs.end(),comp);

        vector<int> result(q);
        vector<pair<int,int>> timeIdx(q);

        for(int i = 0;i<q;i++){
            timeIdx[i] = {queries[i],i};
        }

        sort(timeIdx.begin(),timeIdx.end());

        unordered_map<int,int> mpp;
        int i = 0;
        int j = 0;

        for(auto [time,idx] : timeIdx){
            int start = time-x;
            int end = time;

            // window expansion
            while(j<m && logs[j][1] <= end){
                mpp[logs[j][0]]++;
                j++;
            }

            //window shrink
            while(i < m && logs[i][1] < start){
                mpp[logs[i][0]]--;
                if(mpp[logs[i][0]] == 0){
                    mpp.erase(logs[i][0]);
                }
                i++;
            }

            result[idx] = n-mpp.size();
        }
        return result;
    }
};