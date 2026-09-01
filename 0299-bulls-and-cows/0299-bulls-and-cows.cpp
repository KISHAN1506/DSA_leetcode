class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mpp;
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                mpp[secret[i]]++;
            }
        }
        
        
        for (int i = 0; i < guess.length(); i++) {
            if (secret[i] != guess[i]) {
                if (mpp[guess[i]] > 0) {
                    cow++;
                    mpp[guess[i]]--;
                }
            }
        }

        string strg = to_string(bull) + "A" + to_string(cow) + "B";
        return strg;
    }
};