class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int len = 0;

        while (i >= 0 && s[i] == ' ') { // to remove spaces from last
            i--;
        }

        while (i >= 0 && s[i] != ' ') { // count
            len++;
            i--;
        }

        return len;
    }
};