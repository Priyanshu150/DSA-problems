class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = 0;
        int len = 0, maxLen = 0, gap = 2*k;

        while(left<n && right<n){
            while(right<n && nums[right] - nums[left] <= gap){
                len++;
                right++;
            }
            maxLen = max(len, maxLen);
            len--;
            left++;
        }
        return maxLen;
    }
};