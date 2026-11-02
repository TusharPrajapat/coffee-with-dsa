class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<double, int>> ratio;
        double total = 0.0;
        
        for(int i = 0; i < val.size(); i++){
            ratio.push_back({((double)val[i]/wt[i]), i});
        }
        
        //sort this ratio so that we will get those value where we can add more
        sort(ratio.rbegin(), ratio.rend());
        
        for(int i = 0; i < ratio.size(); i++){
            int idx = ratio[i].second;
            
            if(wt[idx] <= capacity){
                total += val[idx];
                capacity -= wt[idx];
            }
            else {
                total += ((double)val[idx]/wt[idx]) * capacity;
                break;
            }
        }
        
        return total;
    }
};
