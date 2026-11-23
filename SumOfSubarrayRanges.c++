class Solution {
public:
    //previous greator equal element
    vector<int> findPGEE(vector<int>& num){
        int n = num.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && num[i] >= num[st.top()]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    //next greator element
    vector<int> findNGE(vector<int>& num){
        int n = num.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && num[i] > num[st.top()]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMax(vector<int>& nums){
        vector<int> pgee = findPGEE(nums);
        vector<int> nge = findNGE(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            int l = i - pgee[i];
            int r = nge[i] - i;

            long long freq = 1LL * l * r; //always write 1LL before calculation
            long long val = freq * nums[i] * 1LL;

            sum = sum + val;
        }

        return sum;
    }

    //previous smaller equal element
    vector<int> findPSEE(vector<int>& num){
        int n = num.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && num[i] < num[st.top()]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    //next small element
    vector<int> findNSE(vector<int>& num){
        int n = num.size();

        vector<int> ans(n, 0);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && num[i] <= num[st.top()]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }
    
    long long sumSubarrayMin(vector<int>& nums){
        vector<int> psee = findPSEE(nums);
        vector<int> nse = findNSE(nums);

        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            int l = i - psee[i];
            int r = nse[i] - i;

            long long freq = 1LL *l * r; //always write 1LL before calculation
            long long val = freq * nums[i] * 1LL;

            sum = sum + val;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};
