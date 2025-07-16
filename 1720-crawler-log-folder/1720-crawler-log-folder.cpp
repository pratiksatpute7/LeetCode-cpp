class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        int push = 0;
        int pop = 0;

        for(auto op : logs) {
            if(op != "../" && op != "./") {
                st.push(op);
                push++;
            } else {
                if(!st.empty() && op == "../") {
                    st.pop();
                    pop++;
                }
            }
        }

        return push - pop;
    }
};