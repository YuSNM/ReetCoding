class Solution {
    
private:
    const vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> db;
        for (string& word : words) {
            string temp = "";
            for (auto c : word)
                temp += morse[c-'a'];
            db.insert(temp);
        }
        return db.size();
    }
    
};