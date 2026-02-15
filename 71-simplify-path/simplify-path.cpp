class Solution {
public:
    string simplifyPath(string str) {

        stack<string> st;

        for(int i = 0 ;i<str.length();i++){
            if(str[i]=='/') continue;

            string token = "";
            while(i<str.length() && str[i] != '/'){
                token+=str[i];
                i++;
            }
            i--;

            if(token == "." || token=="") {
                continue;
            }else if(token == ".."){
                if(!st.empty())st.pop();
            }else{
                st.push(token);
            }
        }

        if(st.empty()) return "/";

        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top()+ans;
            st.pop();
        }

        return ans;

        // This logic is character wise which keeps breaking , we need to thing of making it as different tokens between /
        // stack<string> ansSt;

        // for(int i = 0;i<str.length();i++){
        //     if(!ansSt.empty() && str[i] == '/' && ansSt.top() != "/"){
        //         continue;
        //     }

        //     else if(!ansSt.empty() && str[i] == '/' && ansSt.top() == "/"){
        //         continue;
        //     }

        //     else if(str[i] == '.'){
        //         string tempVal = "";
        //         while(str[i] == '.'){
        //             tempVal += str[i];
        //             i++;
        //         }
        //         i--;

        //         if(tempVal == ".."){
        //             if(!ansSt.empty())ansSt.pop();
        //         }else{
        //             if(tempVal == ".") continue;
        //             ansSt.push(tempVal);
        //         }
                
        //     }
        //     else{
        //         string tempStrDir = "";
        //         while(i<str.length() && str[i] != '/' ){
        //             tempStrDir += str[i];
        //             i++;
        //         }
        //         i--;
        //         ansSt.push(tempStrDir);
        //     }
        // }

        // string ansPath = "";
        // while(!ansSt.empty()){
        //     string tempAnsPathPart = "";
        //     tempAnsPathPart = "/"+ansPath;
        //     tempAnsPathPart = ansSt.top()+ansPath;

        //     ansPath = tempAnsPathPart + ansPath;
        //     tempAnsPathPart = "";
        //     ansSt.pop();
        // }
        // return ansPath;

    }
};