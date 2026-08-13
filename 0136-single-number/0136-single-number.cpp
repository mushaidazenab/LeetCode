class Solution {
public:
int singleNumber(vector<int> &nums)
{
    // method#1
    // this can be done using hashmaps, or even hashsets
    // in case of hashsets, we'd want to add a value in hashset when it first appears, and when
    // it shows again, we can remove that value. this way, we'll only be left with single occuring
    // number when the loop ends

    // methtod # 2: bit manipulation
    // now what we can use to our advantage in this particular scenario is the property of XOR gate
    // we know, 0 XOR X = X
    // now, suppose we XOR all the values except for the one thta exists only once
    // now most definitely, since they are duplicates, our answer will evaluate to '0'
    // now this is becuase 0 XOR 0 = 0, 1 XOR 1 = 0 (when similar bits are XORed, result is '0')
    // using quite a lot of 'nows' lol
    // anywyas, after all the duplicates are XORed, we are left with '0's all the way
    // and since 0 XOR X = X, our final evaluation would result in the number that appears only once
    // yessss thats it

    int res = 0; // here we'll store the results of XOR evaluations - using 0 here cz ofc 0 XOR X = X
    for (int n : nums)
    {
        res ^= n;
    }
    return res;
}
};