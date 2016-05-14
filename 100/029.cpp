#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int divide(int dividend, int divisor)
{
  if(divisor == 0)
    return INT_MIN;

  if(dividend == 0)
    return 0;

  bool neg = false;
  long long pos_dividend = dividend;
  long long pos_divisor = divisor;
  if(dividend < 0 && divisor > 0) {
    pos_dividend = -1 * dividend;
    pos_divisor = divisor;
    neg = true;
  } else if(dividend > 0 && divisor < 0) {
    pos_dividend = dividend;
    pos_divisor = -1 * divisor;
    neg = true;
  } else if(dividend < 0 && divisor < 0) {
    pos_dividend = -1 * dividend;
    pos_divisor = -1 * divisor;
  }

  if(pos_divisor > pos_dividend)
    return 0;
  if(pos_divisor == pos_dividend)
    return 1;
  
  int pos_quotient = 0;
  long long part_sum = 0;
  long long start = 1;
  long long end = pos_dividend; 
  while(start <= end) {
    long long mid = (start + end) / 2;
    long long min_ = pos_divisor < mid ? pos_divisor : mid;
    long long max_ = pos_divisor >= mid ? pos_divisor : mid;
    long long part_sum = 0;
    if(start == end) {
      pos_quotient = start;
      break;
    }
    
    for(int i = 0; i < min_; ++i) {
      part_sum += mid;
    }

    if(part_sum - pos_divisor < pos_dividend && part_sum >= pos_dividend) {
      cout << "Good: " << mid << " - " << min_ << " - " << max_ << " - " << part_sum << endl;
      pos_quotient = mid - 1;
      break;
    } else if(part_sum < pos_dividend) {
      cout << "Less: " << mid << " - " << min_ << " - " << max_ << " - " << part_sum << endl;
      start = mid + 1;
      cout << "Start = " << start << " - " << "End = " << end << endl;
    } else {
      cout << "Bigger: " << mid << " - " << min_ << " - " << max_ << " - " << part_sum << endl;
      end = mid - 1;
      cout << "Start = " << start << " - " << "End = " << end << endl;
    }
  }

  return (neg ? -1 : 1) * pos_quotient;
}

int main()
{
  long long test = 4294967296;
  cout << test << endl;
  cout << "-1021989372 / -82778243 = " << divide(-1021989372, -82778243) << endl;
  return 1;
}

