class Solution {
    bool box[101][101];
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        if (s1.size() + s2.size() != s3.size())
            return 0;
        
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        
        int i, j, k;
        while (!q.empty()) {
            tie(i, j, k) = q.front();
            q.pop();
            
            if (box[i][j])
                continue;
            box[i][j] = 1;
            if (i < s1.size() && s1[i] == s3[k])
                q.push({i+1, j, k+1});
            if (j < s2.size() && s2[j] == s3[k])
                q.push({i, j + 1, k+1});
        }
    
        return box[s1.size()][s2.size()];
    }
    
};