class Solution {
public:
    int partitionString(string s) {
        vector<int> frq(26);
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(frq[s[i]-'a']){
                cnt++;
                for(int &f : frq) f = 0;
            }
            frq[s[i]-'a']++;
        }
        cnt++;
        return cnt;
    }
};