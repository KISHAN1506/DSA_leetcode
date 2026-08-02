class Solution {
public:
    typedef long long ll;
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";
        string res;

        if((ll)num*(ll)den < 0){
            res += "-";
        }

        ll absNum = labs(num);
        ll absDen = labs(den);

        ll intDiv = absNum/absDen;
        res += to_string(intDiv);

        ll remainder = absNum%absDen;
        if(remainder == 0) return res;

        res += '.';
        unordered_map<int,int> mpp;

        while(remainder != 0){
            if(mpp.find(remainder) != mpp.end()){
                res.insert(mpp[remainder],1,'(');
                res += ')';
                break;
            }
            mpp[remainder] = res.length();

            remainder *= 10;
            int digit = remainder/absDen;
            res += to_string(digit);

            remainder = remainder%absDen;
        }
        return res;
    }
};