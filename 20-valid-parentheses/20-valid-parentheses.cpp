class Solution {
public:
    unordered_map<char, char> map;
    stack<char> st;
    void sett() {
        map['('] = map['['] = map['{'] = 0, map[')'] = '(', map[']'] = '[', map['}']= '{';
    }
    
    bool isValid(string s) {
        sett();
        for(auto& c : s) 
            if(map[c]) {
                if(st.empty() || st.top() != map[c]) return false;
                st.pop();
            }else st.push(c);
        return st.empty();
    }
};