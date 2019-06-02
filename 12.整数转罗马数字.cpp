class Solution 
{
public:
    string intToRoman(int num) 
    {
        vector<string> M = {"", "M", "MM", "MMM"};//1000,2000,3000
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};//0,100,200,300,400,500,600,700,800,900
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};//0，10,20,30,40,50,60,70,80,90
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};//0，1,2,3,4,5,6,7,8,9
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};
