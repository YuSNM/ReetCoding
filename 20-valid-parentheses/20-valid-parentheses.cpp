class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map;
        map['('] = map['['] = map['{'] = 0;
        map[')'] = '(', map[']'] = '[', map['}']= '{';

        for(auto& c : s) 
            if(map[c]) {
                if(st.empty() || st.top() != map[c]) return false;
                st.pop();
            }else st.push(c);
        return st.empty();
    }
};