class Solution {
public:
    int candy(vector<int>& ratings) {
        const int n = ratings.size();
        using T = pair<int, int>;
        using ll = long long;
        vector<T> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = ratings[i];
            v[i].second = i;
        }

        sort(begin(v), end(v));

        ll sum = 0;
        vector<int> values(n);
        for (int i = 0; i < n; i++) {
            int curval = v[i].first;
            int curidx = v[i].second;
            int mx = 1;
            if (curidx + 1 < n) {
                if (ratings[curidx] > ratings[curidx + 1])
                    mx = max(mx, values[curidx + 1] + 1);
            }
            if (curidx > 0) {
                if (ratings[curidx] > ratings[curidx - 1])
                    mx = max(mx, values[curidx - 1] + 1);
            }

            sum += mx;
            values[curidx] = mx;
        }

        return sum;
    }
};