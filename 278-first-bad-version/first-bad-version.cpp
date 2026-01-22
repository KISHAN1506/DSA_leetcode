// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int front = 1;
        int back = n;

        
        int mid = INT_MIN;
        while(front <= back){
            mid = front + ((back - front)/2);
            if(isBadVersion(mid) == true){
                back = mid - 1;
            }else if(isBadVersion(mid) == false){
                front = mid + 1;
            }
        }
        

        return front;
    }
};