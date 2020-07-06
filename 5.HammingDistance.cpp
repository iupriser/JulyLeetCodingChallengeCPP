class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = x ^ y;

        //counting number of zeros
        return countSetBits(res);
    }

    int countSetBits(int num)
    {
        unsigned int count = 0;
        while (num)
        {
            num &= (num - 1);
            count++;
        }
        return count;
    }
};