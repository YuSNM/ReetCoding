//Time: 4 ms (71.34%), Space: 8.3 MB (95.60%) - LeetHub

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st(ops.size());
        int j = 0;

        for (auto& i : ops) {
            if(i=="C") {
                --j;
                continue;    
            }
            if (i=="D") 
                st[j++] = st[j - 1] * 2;
            else if (i=="+") 
                st[j++] = st[j - 1] + st[j - 2];
            else 
                st[j++] = stoi(i);
        }
        
        return accumulate(st.begin(), st.begin() + j, 0);
    }   
};
