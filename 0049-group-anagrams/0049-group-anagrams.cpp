class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mpp;
        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            vector<int> arrTable(26, 0);
            for (auto& it : strs[i]) {
                arrTable[it-'a']++;
            }

            // this arrayTable has been populated with the values;
            // now we can make a new string by just iterating on the arrTable

            string strNew = "";
            for (int i = 0; i < 26; i++) {
                while (arrTable[i] != 0) {
                    strNew += i +'a';
                    arrTable[i]--;
                }
            }

            mpp[strNew].push_back(strs[i]);
        }

        for (auto& it : mpp) {
            result.push_back(it.second);
        }

        return result;
    }
};