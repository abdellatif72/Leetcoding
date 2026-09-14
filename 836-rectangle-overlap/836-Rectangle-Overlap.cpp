class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1], x2 = rec2[2], y2 = rec2[3];
        if(x1>=x2 || y1>=y2) return false;
        
        swap(rec1,rec2);

        x1 = rec1[0], y1 = rec1[1], x2 = rec2[2], y2 = rec2[3];
        if(x1>=x2 || y1>=y2) return false;
        
        swap(rec1,rec2);
        
        return true;
    }
};