// 921. Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string S)
{
    stack<char> st;

    for (char ch : S)
    {
        if (ch == ')')
        {
            if (!st.empty())
            {
                if (st.top() == '(')
                    st.pop();
                else
                    st.push(ch);
            }
            else
            {
                st.push(ch);
            }
        } else {
            st.push(ch);
        }
    }

    if (st.empty())
        return 0;
    else
        return st.size();
}
};
