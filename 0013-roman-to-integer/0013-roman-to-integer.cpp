class Solution {
public:
    int romanToInt(string s) {
        // vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        // vector<int> sym = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        unordered_map<char,int> roman = {
            {'I',1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for(int i = 0;i<s.size()-1;i++){
            if(roman[s[i]] < roman[s[i+1]]){
                ans -= roman[s[i]];
            }else{
                ans += roman[s[i]];
            }
        }

        return ans + roman[s[s.size()-1]];
        
    }
};