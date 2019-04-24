class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int a = num / 1000;
        int b = (num - a * 1000) / 100;
        int c = (num - a * 1000 - b * 100) / 10;
        int d = num - a * 1000 - b * 100 - c * 10;
        string e[] = {"M", "MM", "MMM"};
        string f[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string g[] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string h[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        if (a > 0) {
            res = res + e[a - 1];
        }
        if (b > 0) {
            res = res + f[b - 1];
        };
        if (c > 0) {
            res = res + g[c - 1];
        }
        if (d > 0){
            res = res + h[d - 1];
        }
        return res;
    }
};