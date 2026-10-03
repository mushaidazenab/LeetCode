class Solution {
public:
void reverseHelper(int left, int right, vector<char>& s ){
    if(left == right || left > right){
        return;
    }
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverseHelper(left + 1, right-1, s);
}

    void reverseString(vector<char>& s) {
        if (s.empty()) return;
        reverseHelper(0, s.size() - 1, s);
        return;
    }
};