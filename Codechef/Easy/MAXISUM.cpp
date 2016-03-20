#include <bits/stdc++.h>

typedef long long int ull;

using namespace std;

#define DEBUG 0
#define NEGA  10
#define NEGB  10

int main()
{
	int t;
	ull n,k,i, j, sum = 0, max =0, new_val=0, old_val = 0;
#if DEBUG
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else
	cin >> t;
#endif

	while (t--)
	{
		sum = 0;
		max = 0;
		new_val = 0;
		old_val = 0;
#if DEBUG
		n = (rand()%10)+1; 
		k = (rand()%10)+1; 
		cout <<n<<" "<<k<<endl; 
#else
		cin >> n;
		cin >> k;
#endif
		ull A[n+1], B[n+1];
		memset(A,0, (n+1)*sizeof(ull));
		memset(B,0, (n+1)*sizeof(ull));

		for (i = 1; i <=n; i++)
		{
#if DEBUG
			A[i] = ((rand()%10)+1) - NEGA; 
			cout << A[i]<<" ";
#else
			cin >> A[i];
#endif
		}
#if DEBUG
		cout << endl;
#endif
		for (i = 1; i <=n; i++)
		{
#if DEBUG
			B[i] = ((rand()%10)+1) - NEGB; 
			cout << B[i]<<" ";
#else
			cin >> B[i];
#endif
		}
#if DEBUG
		cout << endl;
#endif
		for (i = 1; i <= n; i++)
		{
			sum = sum + (A[i] * B[i]);
		}
#if DEBUG
		cout << "Original Sum is "<<sum<<endl;
#endif
		max = sum;
		for (i = 1; i <= n; i++)
		{
			if ((A[i] <= 0) && (B[i] <= 0))
			{	
				old_val = A[i] * B[i];
				new_val = (A[i] + (k * -1)) * B[i];
				if (max < sum + (new_val - old_val))
				{
					max = sum + (new_val - old_val);
				}
			}
			else if ((A[i] >= 0) && (B[i] >= 0))
			{
				old_val = A[i] * B[i];
				new_val = (A[i] + (k * 1)) * B[i];
				if (max < sum + (new_val - old_val))
				{
					max = sum + (new_val - old_val);
				}
			}
			else if ((A[i] >= 0) && (B[i] <= 0))
			{
				old_val = A[i] * B[i];
				new_val = (A[i] + (k * -1)) * B[i];
				if (max < sum + (new_val - old_val))
				{
					max = sum + (new_val - old_val);
				}
			}
			else if ((A[i] <= 0) && (B[i] >= 0))
			{
				old_val = A[i] * B[i];
				new_val = (A[i] + (k * 1)) * B[i];
				if (max < sum + (new_val - old_val))
				{
					max = sum + (new_val - old_val);
				}
			}

		}
		if (max > sum)
		{
			cout << max << endl;
		}
		else
		{
#if DEBUG
			cout<<"Max less than sum"<<endl;
#endif
			cout << sum << endl;
		}
	}
	return 0;
}