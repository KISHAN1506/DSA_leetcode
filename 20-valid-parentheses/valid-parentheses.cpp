class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i = 0;i<str.length();i++){
            if(str[i] == '(' ||str[i] == '[' ||str[i] == '{'){
                st.push(str[i]);
            }
            else{
                if(st.empty()) return false;
                if(str[i] == ')' && st.top() == '('){
                    st.pop();
                }
                else if(str[i] == ']' && st.top() == '['){
                    st.pop();
                }
                else if(str[i] == '}' && st.top() == '{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();

        // int ctr1 = 0;
        // int ctr2 = 0;
        // int ctr3 = 0;
        // int ctrmain = 0;
        // for(int i = 0;i<str.length();i++){
        //     if(ctr1 == 0 && str[i] == '('){
        //         ctr1++;
        //     }
        //     if(ctr1 == 1 && str[i] == ')'){
        //         ctr1--;
        //         ctrmain++;
        //     }
        //     if(ctr1 == 0 && str[i] == ')'){
        //         ctr1--;
        //         ctrmain--;
        //     }
        //     if(ctr1 == 1 && (ctr2 == 1 || ctr3 == 1) && str[i] == ')'){
        //         ctrmain--;
        //     }


        //     if(ctr2 == 0 && str[i] == '{'){
        //         ctr2++;
        //     }
        //     if(ctr2 == 1 && str[i] == '}'){
        //         ctr2--;
        //         ctrmain++;
        //     }
        //     if(ctr2 == 0 && str[i] == '}'){
        //         ctr2--;
        //         ctrmain--;
        //     }
        //     if(ctr2 == 1 && (ctr1 == 1 || ctr3 == 1) && str[i] == '}'){
        //         ctrmain--;
        //     }




        //     if(ctr3 == 0 && str[i] == '['){
        //         ctr3++;
        //     }
        //     if(ctr3 == 1 && str[i] == ']'){
        //         ctr3--;
        //         ctrmain++;
        //     }
        //     if(ctr3 == 0 && str[i] == ']'){
        //         ctr3--;
        //         ctrmain--;
        //     }
        //     if(ctr3 == 1 && (ctr1 == 1 || ctr2 == 1) && str[i] == ']'){
        //         ctrmain--;
        //     }
        // }
        
        // if(ctrmain == 0){
        //     return true;
        // }
        // return false;
    }
};