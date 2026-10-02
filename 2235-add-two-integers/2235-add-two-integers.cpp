class Solution {
public:
    int sum(int num1, int num2) {
        //recursive approach
        //add 1 in the first number till the other number becomes zero
        if(num2 == 0){
            return num1;
        }
        if(num2<0)
            return sum(num1 -1, num2+1);
        else
        return sum(num1+1, num2-1);
    }
};