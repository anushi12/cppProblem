bool isValidParenthesis(string s)
{
    // int cntOpenBrackets = 0;
    // int cntCloseBrackets = 0;
    // for(int i = 0 ;i<s.size();i++){
    //     if(s[i] == '{' || s[i]=='(' || s[i]=='['){
    //         cntOpenBrackets++;
    //     }
    //     else cntCloseBrackets++;
    // }
    // if(cntOpenBrackets == cntCloseBrackets)return true;
    // else return false;

    stack<int>st;
    for(int i = 0; i<s.size();i++){
        if(s[i] == '{' || s[i]=='(' || s[i]=='['){
            st.push(s[i]);
        }
        else {
            if(st.empty()) return false;
            char c = st.top();
            if ((c == '{' && s[i] == '}') || (c == '(' && s[i] == ')') ||
                (c == '[' && s[i] == ']'))
              st.pop();
            else
              return false;
        }
    }
        if (st.empty())
            return true;
        else
            return false;
    }
