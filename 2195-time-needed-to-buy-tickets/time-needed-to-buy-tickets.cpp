class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;

        for(int i = 0;i<tickets.size();i++){
            q.push({tickets[i],i});
        }

        int time = 0;
        while(!q.empty()){
            if(q.front().first == 0){
                q.pop();
                continue;
            }
            q.front().first--;
            pair<int,int> val = q.front();
            q.pop();

            time++;
            // check for the person we removed from the line
            if(val.second == k && val.first == 0){
                return time;
            }
            // push after checking, pushing earlier will check the next person
            q.push(val);
        }

        return time;
    }
};