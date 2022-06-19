

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int len = searchWord.size();
        vector<vector<string>> ans(len);
        vector<string> prod;
        for (string& product : products)
            if (product[0] == searchWord[0])
                prod.push_back(product);
        
        sort(prod.begin(), prod.end());
        
        for (int i = 0; i < prod.size(); i++) {
            string& str = prod[i];
            
            for (int j = 0, j_max = min(str.size(), searchWord.size()) ; j < j_max; j++) 
                if (str[j] != searchWord[j]) 
                    break;
                else if (ans[j].size() < 3)
                    ans[j].push_back(str);
        }
        return ans;
    }
};