
struct Trie {
    unordered_map<char, Trie*> next;
    Trie() { };
    
    int insert(const string& word) {
        Trie* node = this;
        int i = word.size() - 1, cnt = 0;
        bool subs = 1, dif = 0;
        
        if (node->next.count(word.back())) {
            subs = 0;
            node = node->next[word[i--]];
            for (; i >= 0 && node->next.count(word[i]); --i) 
                node = node->next[word[i]];
        }
        
        for (; i >= 0; --i) {
            if (!dif && node->next.size())
                dif = 1;
            node->next[word[i]] = new Trie();
            node = node->next[word[i]];
            cnt++;
        }
        if (dif)
            return word.size() + 1;
        return cnt + subs;
    }
};

class Solution {
    Trie root;
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        for (string& word : words)
            ans += root.insert(word);
        return ans;
    }
};