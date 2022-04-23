//Time: 0 ms (100.00%), Space: 7.6 MB (9.59%) - LeetHub


class Solution {
private:
    unordered_map<string, string> enc, dec;
    const string chars = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
public:
    string createCode() {
        string code = "";
        for (int i = 0; i < 5; i++) 
            code += chars[rand() % chars.length()];
        return "http://tinyurl.com/" + code;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (enc.count(longUrl)) return enc[longUrl];
        
        string code = createCode();
        while (dec.count(code)) 
            code = createCode();
        
        enc[longUrl] = code;
        dec[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return dec[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
