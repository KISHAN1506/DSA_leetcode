class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;

        int maxWater = (min(height[l], height[r]) )* (r-l);

        while (l < r) {
            if(height[l] < height[r]) {
                l++;
            }else if (height[r] < height[l]){
                r--;
            }else {
                l++;
                r--;
            }
            int waterNow = min(height[l], height[r]) * (r-l);
            maxWater = max(maxWater, waterNow);
        }
        return maxWater;
    }
};