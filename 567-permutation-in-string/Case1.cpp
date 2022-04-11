//Time: 5 ms (87.02%), Space: 7.3 MB (42.48%) - LeetHub

class Solution {
    int CountS1[128];
    int CountS2[128];
public:
    bool checkCnt(int *a, int *b) {
        for(int c = 'a'; c <= 'z'; c++)
            if(a[c] != b[c]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        
        for(auto& i : s1) ++CountS1[i];
        
        int i = 0;
        while(i < s1.size()) ++CountS2[s2[i++]];
        if (checkCnt(CountS1, CountS2)) return true;
        
        while(i < s2.size()) {
            --CountS2[s2[i - s1.size()]];   //1 CountS2 갱신
            ++CountS2[s2[i++]]; 
        
            if (checkCnt(CountS1, CountS2)) return true;    //2. count 체크
        }
        
        return false;
    }
};
