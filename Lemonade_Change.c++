class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int nCustomers = bills.size();

        int five = 0;
        int ten = 0;
        int twenty = 0;
        for(int i = 0; i < nCustomers; i++){
            if(bills[i] == 5){
                five++;
            }

            else if(bills[i] == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else {
                    return false;
                }
            }

            else {
                if(ten && five){
                    twenty++;
                    ten--;
                    five--;
                }
                else if(five>2){
                    five = five - 3;
                    twenty++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
