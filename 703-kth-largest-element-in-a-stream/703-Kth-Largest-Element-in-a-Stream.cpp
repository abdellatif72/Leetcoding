class KthLargest {
public:

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minpq.push(val);
        if (minpq.size() > k) {
            minpq.pop();
        }
        return minpq.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minpq;
};