class Solution {
public:
    bool isOperator(string &s)
    {
        if(s == "*" || s == "-" || s == "+" ||s == "/")
            return true;
        return false;
    }
    int calculate(int a, int b, char op)
    {
        if(op == '+')
            return b + a;
        else if(op == '-')
            return b - a;
        else if(op == '*')
            return b * a;
        else
            return b / a;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> numbs;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(!isOperator(tokens[i]))
            {
                int n = stoi(tokens[i]);
                numbs.push(n);
            }
            else
            {
                int a = numbs.top();
                numbs.pop();
                int b = numbs.top();
                numbs.pop();
                char op = tokens[i][0];
                int res = calculate(a, b, op);
                numbs.push(res);
            }
        }
        return numbs.top();
    }
};
