class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result (size, 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < size; i++) {
            int temp = temperatures[i];


            while(!st.empty() && temp > st.top().first){
                auto t = st.top();
                st.pop();
                result[t.second] = i - t.second;
            }

            st.push({temp, i});
        }

        return result;
    }
};