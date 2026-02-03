class Solution {
public:
    int search(vector<int>& arr, int target) {
        int si = 0;
        int ei = arr.size()-1;

        while(si<=ei){       
            int mid = si + (ei-si)/2;
            if(arr[mid] == target){
                return mid;
            }

            if(arr[mid]>= arr[si]){ // line 1
                if(arr[si]<=target && target<=arr[mid]){
                    ei = mid-1;
                }else{
                    si = mid+1;
                }
            }else{ // line 2
                if(arr[mid]<=target && target<=arr[ei]){
                    si = mid+1;
                }else{
                    ei = mid-1;
                }
            }
        }
        return -1;

    }
};