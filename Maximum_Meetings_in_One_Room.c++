class Solution {
  public:
    static bool comparator(const tuple<int, int, int> &a, const tuple<int, int, int> &b){
        if(get<1>(a) == get<1>(b)){
            return get<2>(a) < get<2>(b);
        }    
        
        return get<1>(a) < get<1>(b);
    }
    
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        //make pair first {s, f, idx}
        vector<tuple<int, int, int>> meetings;
        
        for(int i = 0; i < f.size(); i++){
            meetings.push_back({s[i], f[i], i+1});
        }
        
        //sort on the basis of finish time in asc order
        sort(meetings.begin(), meetings.end(), comparator);
        
        //make one arr which stores idx of meetings
        vector<int> idxArr;
        int finish = get<1>(meetings[0]);
        idxArr.push_back(get<2>(meetings[0]));
        
        for(int i = 1; i < meetings.size(); i++){
            int start = get<0>(meetings[i]);
            int endTime = get<1>(meetings[i]);
            int idx = get<2>(meetings[i]);
            
            if(start > finish){
                idxArr.push_back(idx);
                finish = endTime;
            }
        }
        
        sort(idxArr.begin(), idxArr.end());
        
        return idxArr;
    }
};
