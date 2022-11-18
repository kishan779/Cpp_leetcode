class Solution 
{
    public:
    bool isUgly(int num) 
    {
        if (num == 0) return false;
        for (int i : {2,3,5})
            while (num % i == 0)
                num /= i;
        return num == 1;
    }
};