class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int curVal = 0;

        for (int i = 0; i < k; ++i) {
            curVal += cardPoints[i];
        }

        int best = curVal;

        for (int i = 0; i < k; ++i) {
            curVal -= cardPoints[k - 1 - i];
            curVal += cardPoints[n - 1 - i];
            best = max(best, curVal);
        }

        return best;
    }
};