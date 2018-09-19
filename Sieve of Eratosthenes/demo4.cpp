//目标：得到自然数100以内的全部素数
//Goal: To pick prime number
//方法：把不大于根号n的所有素数的倍数剔除，剩下的就是素数。
//Way:  To get rid of all multiples of primes that are not greater than the square root of n, and all I'm going to get is prime.

#include<iostream>
#include<cmath>
#include<bitset>

using namespace std;
int main()
{
	int const max_number(100);
	int const max_test((int)sqrt((double)max_number));//max_number-double, max_test-int，两次转型
	//所有小于n的质数至少有个小于根号n的因数

	bitset<max_number + 1>numbers;//101个0！
	numbers.set();//101个1！
	//numbers[0]不理他！
	numbers[1] = 0;
	for(int i(1); i != max_test; ++i)
	{
		if(numbers[i])
		{//筛掉倍数
			for(int j = (i*i); j < max_number + 1; j += i)//
			{
				numbers[j] = 0;
			}
		}
	}

	cout << "The number of primes less than "<< max_number + 1 << " is " << numbers.count() << ".\n\n";

	for(int i(1); i != max_number + 1; ++i)
	{
		if(numbers[i]) cout << i <<endl; 
	}
	return 0;
}
