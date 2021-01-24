/*

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

    The length of both num1 and num2 is < 5100.
    Both num1 and num2 contains only digits 0-9.
    Both num1 and num2 does not contain any leading zero.
    You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/


class Solution {
public:
    
    static const int ZERO_CODE = 48;
   
    string addStrings(string num1, string num2) 
    {
        std::stringstream ss;
        
        int sz1 = num1.size();
        int sz2 = num2.size();
       
        int to_next = 0;
        for(int i=0;i < std::max(sz1, sz2) ;i++)
        {
            int leftNum = (sz1-1-i)>=0?(num1[sz1-1-i]-ZERO_CODE):0;
            int rightNum = (sz2-1-i)>=0?(num2[sz2-1-i]-ZERO_CODE):0;
            
            int currentResult = leftNum + rightNum + to_next;
            to_next = currentResult / 10;
            ss << char((currentResult % 10)+ZERO_CODE);
        }
        
        if(to_next>0)
        {
            ss << char(to_next+ZERO_CODE);
        }
        

        string proxyRes(ss.str()); 
        
        //reverse string 
        string res(proxyRes.rbegin(), proxyRes.rend());
        return res;
    }
};


