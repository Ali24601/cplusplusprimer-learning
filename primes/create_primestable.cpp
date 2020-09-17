/*INT_MAX	time use:922821ms
对于[primes[lastpeerid]*primes[lastpeerid],primes[lastpeerid+1]*primes[lastpeerid+1])中间的每个数，依次用
primes[0:lastpeerid]试探是否可以整除。效果好于用primes[lastpeerid:0]试探是否可以整除（好很多）
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
			for (int j = start; j != end; ++j)
			{				
				bool isprime = true;
				int i = 0;
				while (i < lastpeerid&&j%primes[i])
					++i;				
				if (i == lastpeerid)
					primes.push_back(j);
				if (j == INT_MAX)//END
				{
					ended = true;
					break;
				}					
			}
		}
		return primes;
	}
	
};
