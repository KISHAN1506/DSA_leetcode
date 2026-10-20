class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int result = 0;
        for(int i = 0;i<n;i++){
            int vowel = 0;
            int conso = 0;
            for(int j = i;j<n;j++){
                if(isVowel(s[j])){
                    vowel++;
                }else{
                    conso++;
                }

                if(conso == vowel && ((vowel * conso) % k == 0) ){
                    result++;
                }
            }
        }

        return result;
    }
};