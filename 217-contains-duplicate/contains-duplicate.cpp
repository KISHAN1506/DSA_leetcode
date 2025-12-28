class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            // IF s == 1 then return that value is coming again
            if(s.count(x)) return true;
            s.insert(x);
        }
        return false;
    }
};