class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        queue<int> q;
        for (int i = 0; i < s.size(); i++) 
            if (cnt[s[i]]++ == 0)
                q.push(i);
            
        while (!q.empty()) {
            if (cnt[s[q.front()]] == 1)
                return q.front();
            q.pop();
        }
        
        return -1;
    }
};