class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        for(char c : s) {
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            } else {

                if(!st.empty() && mapping[c] == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
        
    }
};