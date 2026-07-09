class Solution {
public:
    void combs(int open,int close,vector<string>& res,string str){
        if(open == 0 && close == 0){
            res.push_back(str);
            return;
        }
        if(open > 0){
            combs(open-1,close,res,str+"(");
        }
        if(close > 0 && close > open){
            combs(open,close-1,res,str+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        combs(n,n,res,"");
        return res;
    }
};