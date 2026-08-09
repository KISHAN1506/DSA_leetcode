class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                vec.push_back(nums1[i++]);
            }else{
                vec.push_back(nums2[j++]);
            }
        }

        while(i < n){
            vec.push_back(nums1[i++]);
        }
        while(j < m){
            vec.push_back(nums2[j++]);
        }

        if(vec.size() % 2 == 1){
            return vec[vec.size()/2];
        }else{
            return (double)(vec[vec.size()/2 - 1] + vec[(vec.size()/2)])/2;
        }
        return 0;
    }
};