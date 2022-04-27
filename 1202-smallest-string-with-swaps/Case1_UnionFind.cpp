//Time: 178 ms (84.34%), Space: 48.8 MB (83.12%) - LeetHub

class Solution {
    vector<int> parent;
    
public:
    int Findp(int a) {
        if (parent[a] < 0) return a;
        return parent[a] = Findp(parent[a]);
    }
    
    void Union(int a, int b) {
		if ((a = Findp(a)) == (b = Findp(b)))
			return;
        
        if (parent[a] < parent[b]) {
            parent[a] += parent[b];
            parent[b] = a;
        }else {
            parent[b] += parent[a];
            parent[a] = b;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.assign(s.size(), -1);
        unordered_map<int, pair<string, vector<int>>> map;

        for (auto& pi : pairs)
            Union(pi[0], pi[1]);

        for (int i = 0; i < s.size(); i++) {
            map[Findp(i)].first.push_back(s[i]);
            map[Findp(i)].second.push_back(i);
        }

        for (auto& i : map) {
            string& str = i.second.first;
            vector<int>& v = i.second.second;

            sort(str.begin(), str.end());
            sort(v.begin(), v.end());

            for (int i = 0; i < str.size(); i++) 
                s[v[i]] = str[i];

        }

        return s;
    }
};
