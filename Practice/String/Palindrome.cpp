#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;                 // ติดลบไม่เป็น palindrome
        if (x % 10 == 0 && x != 0) return false; // ลงท้ายด้วย 0 (ยกเว้น 0 เอง)

        int revHalf = 0;
        // กลับตัวเลขแค่ครึ่งหลัง เช่น 1221 -> x=12, revHalf=12 / 12321 -> x=12, revHalf=123
        while (x > revHalf) {
            revHalf = revHalf * 10 + (x % 10);
            x /= 10;
        }
        // ถ้าจำนวนหลักเป็นคู่: x == revHalf
        // ถ้าจำนวนหลักเป็นคี่: ตัดหลักกลางทิ้ง revHalf/10
        return (x == revHalf) || (x == revHalf / 10);
    }
};

int main() {
    int n;
    if (cin >> n) {
        Solution s;
        cout << (s.isPalindrome(n) ? "true" : "false") << "\n";
    }
    return 0;
}
