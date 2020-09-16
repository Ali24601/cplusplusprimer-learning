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
