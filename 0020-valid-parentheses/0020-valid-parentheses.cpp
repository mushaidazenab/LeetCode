class Solution {
public:
    bool isValid(string s)
{
    // for every opening brace found, push its closing brace  on stack
    // if the char is not an opening bracket (i.e it is a closing brace)
    // we want to make sure it is equal to top of the stack - rmbr we were pushing closing braces to stack
    // if it is equal then pop
    // if either the stack is empty or the stack top doesnt match then pattern is not valid
    // if we get an epmty stack at the end of our loop, then it means th pattern was valid
    stack<char> st;
    for (char c : s)
    {
        if (c == '(')
        {
            st.push(')');
        }
        else if (c == '{')
        {
            st.push('}');
        }
        else if (c == '[')
        {
            st.push(']');
        }
        else
        {
            if (st.empty() || c != st.top())
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}
};