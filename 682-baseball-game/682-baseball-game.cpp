class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ans = 0;

        for (auto& i : ops) 
            if(i=="C") st.pop();
            else if (i=="D") st.push(st.top() * 2);
            else if (i=="+") {
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1 + temp2); 
            }
            else st.push(stoi(i));

        for(;!st.empty();st.pop()) ans += st.top();
        return ans;
    }   
};