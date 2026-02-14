class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int n = nums2.size();
        stack<pair<int,int>> st;
        vector<int> nge(n);
    
        for(int i = nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first<=nums2[i]){
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else{
                nge[i] = st.top().first;
            }
            st.push({nums2[i],i});
        }


        vector<int> ans;
        for(int i =0;i<nums1.size();i++){
            for(int j = 0; j < n; j++){
                if(nums2[j] == nums1[i]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;


        // vector<int> ans;
        // for(int i = 0;i<nums1.size();i++){
        //     int val = nums1[i];
        //     int j = 0;
        //     while(j<nums2.size()){
        //         if(nums2[j] == val){
        //             break;
        //         }
        //         j++;
        //     }  
        //     j++;

        //     while(j<nums2.size()){
        //         int ctr = 0;
        //         int k = j;
        //         for(;k<nums2.size();k++){
        //             if(nums2[k] > val){
        //                 ans.push_back(nums2[j]);
        //                 ctr = 1;
        //                 break;
        //             }
        //         }
        //         if(ctr == 0){
        //             ans.push_back(-1);
        //         }
        //     }

        // }
        // return ans;
    }
};