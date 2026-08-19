class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mpp;

        for(auto& reservedSeat : reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mpp[row].insert(seat);

        
        }
        int result = (n - mpp.size())*2;

        for(auto& [row,bookedSeats] : mpp){
            auto isAvailable = [&](int seat){
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool grpA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool grpB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool grpC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(grpA && grpC){
                result += 2;
            }else if (grpA || grpB || grpC){
                result += 1;
            }
        }
        return result;
    }
};