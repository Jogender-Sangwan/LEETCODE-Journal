class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> st;
        st.push(-1); // Base index for valid substring boundary

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Update base index
                } else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};
