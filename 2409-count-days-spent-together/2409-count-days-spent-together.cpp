class Solution {
public:
    int findDayOfYear(string date,vector<int>& cumuSumOfMonth){
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3));

        return cumuSumOfMonth[month-1]+day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInEachMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int> cumuSumOfMonth(13); // 13 taken because we'll do 1 based indexing to access directly
        cumuSumOfMonth[1] = 31; // January

        for(int i =2;i<=12;i++){
            cumuSumOfMonth[i] = cumuSumOfMonth[i-1] + daysInEachMonth[i-1];
        }

        int arriveAliceDay = findDayOfYear(arriveAlice,cumuSumOfMonth);
        int leaveAliceDay = findDayOfYear(leaveAlice,cumuSumOfMonth);
        int arriveBobDay = findDayOfYear(arriveBob,cumuSumOfMonth);
        int leaveBobDay = findDayOfYear(leaveBob,cumuSumOfMonth);

        int overlapDays = min(leaveAliceDay,leaveBobDay) - max(arriveAliceDay,arriveBobDay) + 1;

        return max(overlapDays,0); // to sort if no overlap
    }
};