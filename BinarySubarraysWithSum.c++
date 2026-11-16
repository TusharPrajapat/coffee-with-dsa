class Solution {
public:
    int atMost(vector<int>& nums, int goal){
        //edge case
        if(goal < 0){
            return 0;
        }

        int sum = 0, cnt = 0;
        int l = 0, r = 0;

        while(r < nums.size()){
            sum = sum + nums[r];

            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }

            cnt = cnt + (r-l+1);
            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal-1);
    }
};
