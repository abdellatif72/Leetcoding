class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(n+m);

        int i1 = 0, i2 = 0, i3 = 0;;
        while(i1 < m || i2 < n){
            if(i1 < m && i2 < n){
                if(nums1[i1]<=nums2[i2]){
                    nums3[i3++] = nums1[i1++]; 
                } else {
                    nums3[i3++] = nums2[i2++];
                }
            } else if(i1 < m){
                nums3[i3++] = nums1[i1++]; 
            } else{
                nums3[i3++] = nums2[i2++];
            }
        }

        nums1 = nums3;
        nums3.clear();
        nums2.clear();
    }
};