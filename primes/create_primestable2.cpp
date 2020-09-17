/*INT_MAX	time use:9163ms
分配一块堆内存，表示[primes[lastpeerid]*primes[lastpeerid],primes[lastpeerid+1]*primes[lastpeerid+1])直接的每个数是否可以被
primes[0:lastpeerid]整除。与create_primestable.cpp相比，此处采用步进的方式，避免每次都判断是否被整除。用时约为前者的1%，内存多消耗5,203,320B(count的最大值)
*/

class Solution {
public:
	vector<int> findprime()
	{
		vector<int> primes{ 2,3 };
		int lastpeerid = 0;
		bool ended = false;
		while (!ended)
		{
			int lastpeer = primes[lastpeerid];
			int nextpeer = primes[++lastpeerid];
			int start = lastpeer*lastpeer;
			int end = nextpeer*nextpeer;
			int count = end - start;
			if (end <0 )
			{
				count = (long long)INT_MAX + 1 - start;
				ended = true;
			}

			bool *allnum = new bool[count]{0};
			for (int i = 0; i < lastpeerid; ++i)
			{
				int startj = start% primes[i];
				if (startj != 0)
					startj = primes[i] - startj;
				while (startj < count)
				{
					allnum[startj] = true;
					startj += primes[i];
				}
			}
			for (int j = 0; j < count; ++j)
			{
				if (!allnum[j])
					primes.push_back(j + start);
			}
			delete []allnum;
		}
		return primes;
	}
};
