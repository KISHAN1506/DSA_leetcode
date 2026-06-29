class Solution {
public:
    bool letterInString(string pattern,string word){
        int n = pattern.size();
        int m = word.size();
        for(int i = 0;i<m-n+1;i++){
            int len = 0;
            for(int j = 0;j<n;j++){
                if(word[i+j] == pattern[j]) len++;
                else break;
            }
            if(len == n){
                return true;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(letterInString(patterns[i],word)) cnt++;
        }
        return cnt;
    }
};