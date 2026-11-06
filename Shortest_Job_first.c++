class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        
        int waitingTime = 0;
        int totalTime = 0;
        
        for(int i = 0; i < bt.size(); i++){
            waitingTime += totalTime;
            totalTime += bt[i];
        }
        
        return waitingTime / bt.size();
    }
};
