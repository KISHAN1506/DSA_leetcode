class Solution {
public:
    typedef long long ll;
    long long sumAndMultiply(int n) {
        vector<int> digits;
        ll sum = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                digits.push_back(digit);
                sum += digit;
            }
            n /= 10;
        }

        ll num = 0;

        for (int i = digits.size() - 1; i >= 0; i--) {
            num = num * 10 + digits[i];
        }

        return num * sum;
    }
};