class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int l = 0, r = 0;

        int hash[256] = {0};
        int cnt = 0;
        int sIdx = -1;

        for(char ch : t){
            hash[ch]++;
        }

        while(r < s.size()){
            if(hash[s[r]] > 0){
                cnt++;
            }
            
            hash[s[r]]--;

            while(cnt == t.size()){
                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    sIdx = l; 
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return sIdx == -1 ? "" : s.substr(sIdx, minLen);
    }
};
