/**/

int getSum(int a, int b) 
{
        int overflow = 0;
        int sum = 0;
        for(int i = 0; i <= 31; ++i)
        {
            int d1 = (a >> i) & 1;
            int d2 = (b >> i) & 1;
            int s = ((d1 && d2) ? 2 : d1 | d2);
            if(overflow && s == 1)
                s = 2;
            else
                s |= overflow;
                
            overflow = (s >> 1);
            s &= 1;
            sum |= (s << i);
        }
        return sum;
}
