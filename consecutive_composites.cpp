#include<iostream>
#include<vector>

using namespace std;

int check_prime(long n)
{
	for(int i=2;i<=n/2;i++)
	{
		if(n%i == 0)
		{
			return(1);
		}
	}
	return(0);
}

int main()
{
	long x,n;
	int flag;
	vector<long> primes;
	cout<<"Enter number of consecutive composites ";
	cin>>x;
	cout<<"Enter starting number ";
	cin>>n;
	int counter=0;
	while(true)
	{
		flag = check_prime(n);
		if(flag == 1)
		{
			primes.push_back(n);
			counter++;
		}
		else
		{
			if(counter == x)
				break;
			else
			{
				primes.clear();
				counter=0;
			}
		}
		n++;
		cout<<n<<endl;		//comment out if needed
	}
	for(int i=0;i<x;i++)
		cout<<primes[i]<<" ";
}
