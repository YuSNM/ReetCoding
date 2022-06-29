class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), [] (auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        for (auto& v : people)
            ans.insert(ans.begin() + v[1], v);
        return ans;
    }
};