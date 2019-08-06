#include <iostream>
int i=0;
long long ackermann(long long m, long long n) {
	i++;
  if(m == 0)
    return n + 1;
  if(n == 0)
    return ackermann(m - 1, 1);
  return ackermann(m - 1, ackermann(m , n - 1));
}
int main()
{
	std::cout<<ackermann(4,4)<<"\n"<<i;
}
