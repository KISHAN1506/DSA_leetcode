class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int winSum = 0;
        int ansi = 0;
        int ansj = minutes-1;
        for (int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1)winSum += cust[i];
        }
        int maxVal = winSum;
        for (int i = 1; i <= n - minutes;i++) {
            if(grumpy[i-1] == 1)winSum -= cust[i-1];
            if(grumpy[i+minutes-1] == 1)winSum += cust[i+minutes-1];
            if (winSum > maxVal) {
                maxVal = winSum;
                ansi = i;
                ansj = i + minutes - 1;
            }
        }

        int totVal = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0 || (i >= ansi && i <= ansj)) {
                cout << i << " ";
                totVal += cust[i];
            }
        }
        return totVal;
    }
};