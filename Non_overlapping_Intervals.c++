class Solution {
public:
    static bool Comparator(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans;
        
        sort(intervals.begin(), intervals.end(), Comparator);

        int lastEndTime = intervals[0][1];
        int cnt = 1;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= lastEndTime){
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }

        ans = intervals.size() - cnt;
        return ans;
    }
};
