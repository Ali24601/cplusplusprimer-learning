class Solution {
public:
	int findprime(int k)
	{
		vector<int> primes{ 2,3 };
		int lastpeerid = 0;
		while (primes.size() < k)
		{
			int lastpeer = primes[lastpeerid];
			int nextpeer = primes[++lastpeerid];
			if (nextpeer >= INT16_MAX)
			{
				system("pause");
			}
			for (int j = lastpeer*lastpeer; j < nextpeer*nextpeer; ++j)
			{
				bool isprime = true;
				int i = 0;
				while (i < lastpeerid&&j%primes[i])
					++i;				
				if (i == lastpeerid)
					primes.push_back(j);
			}
		}
		
		primes.resize(k);
		return primes[k-1];
	}
	
};
