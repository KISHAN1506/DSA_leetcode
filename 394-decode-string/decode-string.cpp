class Solution {
public:
    string decodeString(string str) {
        stack<int> numberSt;
        stack<string> stringSt;

        for(int i = 0;i<str.length();i++){
            if(str[i] == ']'){
                string tempstr = "";
                while(!stringSt.empty()&& stringSt.top() != "["){
                    tempstr = stringSt.top() + tempstr;
                    stringSt.pop();
                }
                stringSt.pop();

                int val = numberSt.top();
                numberSt.pop();
                string org = tempstr;
                while(val != 1){
                    tempstr += org;
                    val--;
                }

                stringSt.push(tempstr);

            }else{
                if(isdigit(str[i])){
                    // be careful for 2 3 digit number
                    int num = 0;
                    while(i<str.length() && isdigit(str[i])){
                        num = num * 10 + (str[i] - '0');
                        i++;
                    }

                    numberSt.push(num);
                    i--; // b/c for loop will also do 1 i++; to not skip 1 character


                }else{
                    stringSt.push(string(1,str[i]));
                }
            }
        }

        string ans = "";
        while(!stringSt.empty()){
            string tempVal = stringSt.top();
            ans = tempVal + ans;
            stringSt.pop();
        }
        return ans;
    }
};