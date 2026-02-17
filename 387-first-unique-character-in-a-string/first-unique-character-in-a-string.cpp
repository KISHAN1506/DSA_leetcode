class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256] = {0};
        queue<pair<char,int>> q;

        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            freq[ch]++;
            q.push({ch,i});

            while(!q.empty() && (freq[q.front().first] > 1)){
                q.pop();
            }
        }


        return q.empty()?-1:(q.front().second);
        
    }
};