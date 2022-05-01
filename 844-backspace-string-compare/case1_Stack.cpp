//Time: 2 ms (47.87%), Space: 6.5 MB (6.98%) - LeetHub

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st1, st2;
        for (auto& c : s) 
            if (c != '#')
                st1.push(c);
            else if (!st1.empty())
                st1.pop();
        
        for (auto& c : t) 
            if (c != '#')
                st2.push(c);
            else if (!st2.empty())
                st2.pop();
        
        if (st1.size() != st2.size()) 
            return false;
        
        for (;!st1.empty(); st1.pop(), st2.pop()) 
            if (st1.top() != st2.top()) 
                return false;
        
        return true;
    }
};
