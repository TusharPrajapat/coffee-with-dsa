class Solution {
public:
    int atMost(vector<int>& arr, int k){
        if(k < 0){
            return 0;
        }

        int l = 0, r = 0;
        int sum = 0, cnt = 0;

        while(r < arr.size()){
            sum = sum + (arr[r] % 2);

            while(sum > k){
                sum = sum - (arr[l] % 2);
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;
        }

        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
