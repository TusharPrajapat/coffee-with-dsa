//Approach --> Sliding window + 2 pointers

class Solution {
public:
    // T.C. => 4ms
    // int numberOfSubstrings(string s) {
    //     int n = s.size();
    //     int ans = 0;
    //     int left = 0;

    //     //window side --> |0|1|2|
    //     vector<int> freq(3,0);

    //     //right --. expand window
    //     for(int right = 0; right < s.size(); right++){
    //         freq[s[right] - 'a']++;

    //         while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
    //             ans += n - right; //Once a window contains all three characters (a, b, c), every substring formed by extending that window towards the right will also be valid.

    //             //left --> shrink window
    //             freq[s[left] - 'a']--;
    //             left++;
    //         }
    //     }

    //     return ans;
    // }

    // T.C. => 7ms
    int numberOfSubstrings(string s) {

        //window side --> |0|1|2|
        int freq[3] = {-1,-1,-1};
        int cnt = 0;
        
        //i --. expand window
        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a'] = i;

            if(freq[0] != -1 && freq[1] != -1 && freq[2] != -1){
                cnt += 1 + min({freq[0], freq[1], freq[2]});
            }

        }

        return cnt;
    }
};
