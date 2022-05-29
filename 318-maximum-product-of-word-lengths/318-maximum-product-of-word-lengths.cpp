class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> v;
        
        for (auto& str : words) {
            int bit = 0;
            for (char c : str)
                bit |= 1 << (c - 'a');
            v.push_back(bit);
        }
        
        for (int i = 0 ; i < v.size(); i++)
            for (int j = i + 1; j < v.size(); j++)
                if (!(v[i] & v[j]))
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
        
        return ans;
    }
};