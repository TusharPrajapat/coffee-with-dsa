class Solution {
private:
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return ans;
    }

    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);

        int n = arr.size();

        int mod = 1e9 + 7;

        int sum = 0;

        for(int i=0; i< n; i++){
            int l = i - pse[i];
            int r = nse[i] - i;

            long long freq = l*r;

            long long val = freq * arr[i];
            
            sum = (sum + val) % mod;
        }

        return sum;
    }
};
