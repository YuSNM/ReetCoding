
struct Trie {
    Trie* next[27];
    int index;
    
    Trie() : index(0) {
        memset(next, 0, sizeof(next));
    }
    
    void insert(const string word, int index) {
        Trie* node = this;
        for (auto c : word) {
            int idx = c - 'a';
            if (!node->next[idx])
                node->next[idx] = new Trie();
            node = node->next[idx];
            node->index = index;
        }
        
    }
    
    int findidx(const string word) {
        Trie* node = this;
        for (auto c : word) {
            int idx = c - 'a';
            if (!node->next[idx])
                return -1;
            node = node->next[idx];
        }
        return node->index;
    }
};

class WordFilter {

private:
    Trie root;
public:
    WordFilter(vector<string>& words) {
        int idx = 0;
        for (auto& word : words) {
            string temp = "{" + word;
            for (int i = word.size() - 1, j = i < 10 ? 0 : j - 9; i >= j; i--) 
                root.insert(temp = word[i] + temp, idx);
            ++idx;
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = suffix + "{" + prefix;
        return root.findidx(temp);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */