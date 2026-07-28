class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a']++;
        }

        string ans(n, 'a');
        int front = 0;
        int back = n - 1;
        for (int i = 0; i < 26; i++) {
            while (arr[i] >= 2) {
                ans[front++] = char(i + 'a');
                ans[back--] = char(i + 'a');
                arr[i] -= 2;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] % 2 == 1) {
                ans[n / 2] = (char)(i + 'a');
                break;
            }
        }

        return ans;
    }
};