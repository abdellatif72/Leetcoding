class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> frq1(26, 0), frq2(26,0);
        for(const char &c: s){
            frq1[c-'a']++;
        }
        for(const char &c: t){
            frq2[c-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(frq1[i]!=frq2[i]) return false;
        }

        return true;
    }
};