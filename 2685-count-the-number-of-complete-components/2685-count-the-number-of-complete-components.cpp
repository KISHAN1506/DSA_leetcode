class Solution {
public:
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj,int &nodes,int &edges){
        vis[i] = 1;
        nodes++;
        edges += adj[i].size();

        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,vis,adj,nodes,edges);
            }
        }
    }

    int giveComponents(int n,vector<vector<int>> &adj){
        vector<int> vis(n,0);
        int comp = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                int nodes = 0;
                int edges = 0;

                dfs(i,vis,adj,nodes,edges);

                edges /= 2;
                if (edges == (nodes * (nodes - 1)) / 2) {
                    comp++;
                }
            }
        }
        return comp;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        return giveComponents(n,adj);

    }
};