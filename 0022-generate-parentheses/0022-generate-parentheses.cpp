class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> st;
        vector<string> res;
        backtracking(res, st, 0, 0, n);

        return res;
    }


    void backtracking(vector<string>& res, stack<char>& st, int openp, int closep, int n) {

        // stop if open count and closed count is same
        if(openp == closep && openp == n) {
            stack<char> tempStack = st;
            string result = "";
            while (!tempStack.empty()) {
                result = tempStack.top() + result;
                tempStack.pop();
            }

            res.push_back(result);
        }

        // we can add a open para if its less than n
        if(openp < n) {
            //we are pushing and poping because we are kinda simulating the tree and back traking 
            // to emulated choosing another option 
            st.push('(');
            backtracking(res, st, openp + 1, closep, n);
            st.pop();
        }

        // we can add a closed para if its count is less than open para
        if(closep < openp) {
            st.push(')');
            backtracking(res, st, openp, closep + 1, n);
            st.pop();
        }
    }
};