class Solution {
public:
    string doOpns(string s, int k){
        int i = 0;
        string newStr = "";
        while(i < s.length()){
            int sumVal = 0;
            for(int j = 0;j<k && i + j < s.length();j++){
                sumVal += s[i+j]-'0';
            }
            newStr += to_string(sumVal);
            i+=k;
        }

        return newStr;
    }

    string digitSum(string s, int k) {
        string ans = s;
        while(ans.length() > k){
            ans = doOpns(ans,k);
        }

        return ans;
    }
};