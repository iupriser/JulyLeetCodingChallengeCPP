class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0x0;
        uint32_t mask = 0x0001;
        for (int i = 0; i < 32; ++i)
        {
            ans <<= mask;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};

/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // start packing from left to right
        uint32_t result = 0x0;
        uint32_t mask = 0x0001;
        
        int number = n;
        int i =31;
        while(i >= 0){
            result |= (mask & number) << i;
            number = number >> 1;
            i--;
        }
        
        return   result;
        
    }
};
*/

/*
int swapBits32(int a) {

a = ((a & 0xFFFF0000) >> 16) | ((a & 0x0000FFFF) << 16);
a = ((a & 0xFF00FF00) >> 8) | ((a & 0x00FF00FF) << 8);
a = ((a & 0xF0F0F0F0) >> 4) | ((a & 0x0F0F0F0F) << 4);
a = ((a & 0xCCCCCCCC) >> 2) | ((a & 0x33333333) << 2);
a = ((a & 0xAAAAAAAA) >> 1) | ((a & 0x55555555) << 1);

return a;
}
*/