class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        vector<string> res;
        backtracking(res, st, 0, 0, n);

        return res;
    }


    void backtracking(vector<string>& res, stack<char>& st, int openp, int closep, int n) {
        if(openp == closep && openp == n) {
            stack<char> tempStack = st;
            string result = "";
            while (!tempStack.empty()) {
                result = tempStack.top() + result;
                tempStack.pop();
            }

            res.push_back(result);
        }

        if(openp < n) {
            st.push('(');
            backtracking(res, st, openp + 1, closep, n);
            st.pop();
        }

        if(closep < openp) {
            st.push(')');
            backtracking(res, st, openp, closep + 1, n);
            st.pop();
        }
    }
};