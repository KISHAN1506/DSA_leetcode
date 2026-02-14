class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n);
        vector<int> nsl(n);
        stack<int> st;

        // next smaller left;
        nsl[0] = -1;
        st.push(0);
        
        for(int i = 1;i<n;i++){
            int curr = heights[i];
            while(!st.empty() && curr <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsl[i] = -1;
            }else{
                nsl[i] = st.top();
            }

            st.push(i);
        }

        //next smallest right
        while(!st.empty()){
            st.pop();
        }

        nsr[n-1] = n;
        st.push(n-1);

        for(int i = n-2;i>=0;i--){
            int curr = heights[i];
            while(!st.empty() && curr <= heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st.top();
            }

            st.push(i);
        }

        int maxArea = INT_MIN;
        for(int i = 0;i<n;i++){
            int height = heights[i];
            int width = nsr[i] - nsl[i] - 1;
            int area = height * width;

            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};