class BrowserHistory {
   
public:
    stack<string> backHistory;
    stack<string> forwardHistory;
    BrowserHistory(string homepage) {
        backHistory.push(homepage);
        forwardHistory = stack<string>();
    }
    
    void visit(string url) {
        backHistory.push(url);
        forwardHistory = stack<string>();

    }
    
    string back(int steps) {
        while(steps > 0 && backHistory.size() > 1) {
            forwardHistory.push(backHistory.top());
            backHistory.pop();
            steps--;
        }

        return backHistory.top();        
    }
    
    string forward(int steps) {
        while(steps > 0 && !forwardHistory.empty()) {
            backHistory.push(forwardHistory.top());
            forwardHistory.pop();
            steps--;
        }

        return backHistory.top();  
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */