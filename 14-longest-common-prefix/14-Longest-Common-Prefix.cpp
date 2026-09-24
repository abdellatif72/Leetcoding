class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int r = 201;
        int sz = -1;
        for(const string& s : strs){
            if(s.empty()) return "";
            sz = (int)s.size();
            r = min(r, sz);
        }

        sz = (int)strs.size();
        string ret = "";
        bool stop = false;
        for(int i = 0; i < r; i++){
            for(int j = 1; j < sz; j++){
                if(strs[j][i]!=strs[j-1][i]) {
                    stop = true;
                    break;
                }
            }
            if(stop){
                break;
            } else {
                ret.push_back(strs[0][i]);
            }
        }


        return ret;
    }
};