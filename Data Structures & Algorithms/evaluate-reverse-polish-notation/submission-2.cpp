class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i = 0;
        while(i < tokens.size())
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")//check if integer
            {
                st.push(stoi(tokens[i]));
            }
            else//if operand
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(tokens[i] == "+")
                {
                    st.push(a + b);
                }
                else if(tokens[i] == "-")
                {
                    st.push(b - a);
                }
                else if(tokens[i] == "*")
                {
                    st.push(a * b);
                }
                else if(tokens[i] == "/")
                {
                    st.push(b / a);
                }
            }
            i++;
        }
        int val = st.top();
        return val;
    }
};
