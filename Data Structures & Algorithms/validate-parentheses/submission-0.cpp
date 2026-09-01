class Solution {
public:
    bool isValid(string s) {
        map<char, char> elements;
        stack<char> my_stack;
        elements['}'] = '{';
        elements[']'] = '[';
        elements[')'] = '(';
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                my_stack.push(s[i]);
            else
            {
                if(!my_stack.empty() && my_stack.top() == elements[s[i]])
                    my_stack.pop();
                else
                    return false;
            }
        }
        if(my_stack.size() != 0)
            return false;
        else 
            return true;
    }
};
