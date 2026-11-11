class Solution {
  public:
  //APROACH USING QUEUE
    // int minPlatform(vector<int>& arr, vector<int>& dep) {
    //     // code here
    //     sort(arr.begin(), arr.end());
    //     sort(dep.begin(), dep.end());
    //     queue<int> que;
    //     //initially
    //     que.push(dep[0]);
    //     int platformCnt = 1;
        
    //     for(int i = 1; i < arr.size(); i++){
    //         if(que.front() < arr[i]){
    //             que.pop();
    //             que.push(dep[i]);
    //         }
    //         else{
    //             platformCnt++;
    //             que.push(dep[i]);
    //         }
    //     }
    //     return platformCnt;
    // }
    
    //APROACH USING 2 POINTERS
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        //initially
        int ans = 1;
        int cnt = 1;
        int i = 1;
        int j = 0;
        
        while(i < arr.size() && j < dep.size()){
           if(arr[i] <= dep[j]){
               cnt++;
               i++;
           }
           else{
               cnt--;
               j++;
           }
           
           ans = max(ans, cnt);
       }
       
       return ans;
    }
};
