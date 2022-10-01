class Solution {
public:
    int numDecodings(string s) {
        int curMultiple = 1;
        int curLength = 0;
        int prevNum = 3;
        for (auto& x : s){
            int a = x - '0';
            if (a == 0){
                if (prevNum > 2) return 0;
                curMultiple *= findMultiple(--curLength);
                curLength = 0;
            }
            else if (a == 1 || a == 2){
                ++curLength;
            }
            else if (a > 2){
                if (a + prevNum * 10 < 27) ++curLength;
                curMultiple *= findMultiple(curLength);
                curLength = 0;
            }
            prevNum = a;
        }
        curMultiple *= findMultiple(curLength);
        return curMultiple;
    }
    int findMultiple(int n) {
        n++;
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
};