class Solution {
public:
    int trap(vector<int>& v) {
        int ans = 0;

    int n = v.size();
    vector<int> left(n);
    left[0]=v[0];
    for (int i = 1; i < n; ++i) {
        left[i]= max(left[i-1], v[i]);
    }

    vector<int> rigght(n);
    rigght[n-1] = v[n-1];
    for (int i = n-2; i>=0; i--) {
        rigght[i] = max(rigght[i+1], v[i]);
    }

    for (int i = 0; i < n; ++i) {
        ans += min(rigght[i],left[i]) - v[i];
    }
    return ans;
    }
};