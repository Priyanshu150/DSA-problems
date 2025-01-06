class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size(), res = 1;
        vector<int> freq(1e6+1, 0);

        for(int i=0; i<n; ++i){
            int st = max(0, nums[i]-k);
            int end = min<long long>(1e6, nums[i]+k);
            freq[st] += 1;
            freq[end+1] -= 1;
        }
        int sum = 0;
        for(int i=0; i<=1e6; ++i){
            sum += freq[i];
            res = max(sum, res);
        }
        return res;
    }
};
