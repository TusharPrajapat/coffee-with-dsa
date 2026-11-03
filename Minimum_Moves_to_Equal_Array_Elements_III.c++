class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = 0;
        int minMoves = 0;
        for(int i = 0; i < nums.size(); i++){
            maxNum = max(maxNum, nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < maxNum){
                minMoves = minMoves + (maxNum - nums[i]);
            }
        }

        return minMoves;
    }
};
