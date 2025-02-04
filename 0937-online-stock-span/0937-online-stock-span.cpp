class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int temp = 0;
        if(st.empty() || st.top().first > price){
            st.push({price, temp + 1});
            return 1;
        }


        while(!st.empty() && st.top().first <= price) {
            auto pair = st.top();
            st.pop();
            temp += pair.second;
        }

        st.push({price, temp + 1});

        return temp + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */