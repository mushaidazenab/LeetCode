class Solution {
public:
    bool isValid(string s)
    {
        // a stack to keep track of opening brackets as we encounter them
        std::stack<char> st;

        // hash map to look up the matching opening bracket for each closing bracket
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}};

        // iterating through each character in the string
        for (char c : s)
        {
            // check if the current character is a closing bracket (exists in our map)
            if (closeToOpen.count(c))
            {
                // if stack is not empty and the top of the stack matches the expected opening bracket
                if (!st.empty() && st.top() == closeToOpen[c])
                {
                    st.pop(); // Remove the matched opening bracket from the stack
                }
                else
                {
                    // otherwise, it's a mismatch or a closing bracket with no opening partner
                    return false;
                }
            }
            else
            {
                // if it's an opening bracket, push it onto the stack
                st.push(c);
            }
        }

        // if the stack is completely empty, all brackets were matched properly
        return st.empty();
    }
};