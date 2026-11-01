class Solution {
public:
    //Approach using HashTable -> T.C = 5 ms
    // int lengthOfLongestSubstring(string s) {
    //     int l = 0, r = 0;
    //     int maxLen = 0;

    //     int hash[256];

    //     for(int i = 0; i < 256; i++){
    //         hash[i] = -1;
    //     }

    //     while(r < s.size()){
    //         if(hash[s[r]] != -1){
    //             l = max(l, hash[s[r]]+1);
    //         }

    //         int len = r - l + 1;
    //         maxLen = max(maxLen, len);

    //         hash[s[r]] = r;
    //         r++;
    //     }

    //     return maxLen;
    // }

    //Approach using HashMap -> T.C = 45 ms
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxLen = 0;

        unordered_map<char, int> mpp;

        while(r < s.size()){
            if(mpp.find(s[r]) != mpp.end()){
                l = max(l, mpp[s[r]] + 1);
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            mpp[s[r]] = r;
            r++;
        }

        return maxLen;

        return maxLen;
    }
};
