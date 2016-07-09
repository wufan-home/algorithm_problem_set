/*
  Your task is to calculate ab mod 1337 where a is a positive integer and 
  b is an extremely large positive integer given in the form of an array.
  Example1:
  a = 2
  b = [3]
  Result: 8
  Example2:
  a = 2
  b = [1,0]
  Result: 1024

  Solution: Similar method for the problem "Power" but use the ten-digit model.
  Take care about the overflow of each power.
*/

int power(long long a, int index)
{
        int prod = 1;
        for(int i = 0; i < index; ++i)
		prod = (prod * a) % 1337;
        return prod;
}
    
int Calculate(long long a, vector<int>& b, int cur)
{
        if(cur == 0)
		return power(a, b[cur]);
        else
		return (power(Calculate(a, b, cur - 1), 10) * power(a, b[cur])) % 1337;
}

int superPow(int a, vector<int>& b)
{
        if(a == 1337)
		return 0;
        
        if(a > 1337)
		a = a % 1337;

        return Calculate(a, b, b.size() - 1);
}
