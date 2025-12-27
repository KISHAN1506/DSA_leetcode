class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> smallestPrice(prices.size(),INT_MAX);

        int smPrc = INT_MAX;
        for(int i = 0;i<prices.size();i++){
            if(prices[i] < smPrc){
                smPrc = prices[i];
            }
            smallestPrice[i] = smPrc;
        }

        vector<int> profit;

        for(int i = 0;i<smallestPrice.size();i++){
            profit.push_back(prices[i] - smallestPrice[i]);
        }

        int maxProfit = 0;
        for(int i = 0;i<profit.size();i++){
            if(profit[i] > maxProfit){
                maxProfit = profit[i];
            }
        }
        return maxProfit;
    }
};