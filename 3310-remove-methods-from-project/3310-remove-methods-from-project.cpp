class Solution {
public:
    void bfs(vector<bool>& suspecious,int k){

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> inDegree(n,0);
        int len = invocations.size();
        vector<vector<int>> adj(n);

        for(int i = 0;i<len;i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        vector<bool> suspecious(n,false);
        queue<int> q;
        q.push(k);
        suspecious[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int &ngbr : adj[curr]){
                if(!suspecious[ngbr]){
                    suspecious[ngbr] = true;
                    q.push(ngbr);
                }
                inDegree[ngbr]--;
            }
        }

        vector<int> ans;
        bool cantRemove = false;
        for(int i = 0;i<n;i++){
            if(suspecious[i] && inDegree[i] > 0){
                cantRemove = true;
                break;
            }
            if(!suspecious[i]){
                ans.push_back(i);
            }
        }


        if(cantRemove){
            vector<int> vec(n);
            for(int i = 0;i<n;i++){
                vec[i] = i;
            }
            return vec;
        }

        return ans;
    }
};