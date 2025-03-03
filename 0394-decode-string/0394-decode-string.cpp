class Solution {
public:
    string decodeString(string s) {

        stack<string> st;

        for(auto ch : s) {
            if(ch == ']') {
                string stringToRepeat = "";
                while (!st.empty() && st.top() != "[") {
                    stringToRepeat += st.top();
                    st.pop();
                }
                // remove [
                st.pop();

                // create numeric number
                string numericTimes = "";
                // [0] because we are using string 
                while (!st.empty() && isdigit(st.top()[0])) {
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(), numericTimes.end());
                int n = stoi(numericTimes);

                // final decoding
                string currDecode = "";
                while (n--) {
                    currDecode += stringToRepeat;
                }
                st.push(currDecode);

            } else {
                string temp(1, ch);
                st.push(temp);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};