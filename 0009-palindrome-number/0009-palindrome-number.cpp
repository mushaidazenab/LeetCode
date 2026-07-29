class Solution {
public:
    bool isPalindrome(int x) {
if(x<0)
return false;
long long div = 1;
while(x>=div*10){
    div*=10;
}
int right, left;
 while(x!=0){
right = x%10;  //get value on right
left = x/div;  //get value on left

if(left!=right){
    return false;
}
 x = x%div;  //remove left digit
 x = x/10;   //remove right digit

 div = div/100;  //we always would want to remove two zeros from div
 }
  return true;
    }
};