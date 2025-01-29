class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        vector<string> op = {"+", "-", "*", "/"};
        for(string str : tokens) {
            int token;
            if(find(op.begin(), op.end(), str) == op.end()){
                token = stoi(str);
                stack.push(token);
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();

                int res;

                switch(str[0]) {
                    case '+':
                        res = op2 + op1;
                        break;
                    case '-':
                        res = op2 - op1;
                        break;
                    case '/':
                        res = op2 / op1;
                        break;
                    case '*':
                        res = op2 * op1;
                        break;
                }

                stack.push(res);
            }
        }

        return stack.top();
    }
};