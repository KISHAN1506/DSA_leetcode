class Solution {
public:
    bool isAnagram(string str1, string str2) {
        int hash1[256] = {0};
        int hash2[256] = {0};

        for(int i = 0;i<str1.length();i++){
            hash1[str1[i]]++;
        }
        for(int i = 0;i<str2.length();i++){
            hash2[str2[i]]++;
        }

        for(int i = 0;i<256;i++){
            if(hash1[i] != hash2[i]){
                return false;
            }
        }
        return true;

    }
};