#include <bits/stdc++.h>

typedef long long int ull;

using namespace std;

#define DEBUG 0
#define NUM_COL 3
#define INFINITE 99999999999

ull num_valid_bags(ull colRed,
				   ull colGreen,
				   ull colBlue)
{
	int cnt = 0;

	if (colRed)
	{
		cnt++;
	}
	if (colGreen)
	{
		cnt++;
	}		
	if (colBlue)
	{
		cnt++;
	}

	return cnt;

}

ull get_smallest(ull colRed,
				 ull colGreen,
				 ull colBlue,
				 ull *numValid)
{
	ull small = 0;
	ull cnt = 0;

	if (colRed)
	{
		cnt++;
	}
	if (colGreen)
	{
		cnt++;
	}		
	if (colBlue)
	{
		cnt++;
	}

	*numValid = cnt;

	if (!colRed)
	{
		colRed = INFINITE;
	}

	if (!colGreen)
	{
		colGreen = INFINITE;
	}

	if (!colBlue)
	{
		colBlue = INFINITE;
	}

	if (colRed < colGreen)
	{
		if (colRed < colBlue)
		{
			small = colRed;
		}
		else
		{
			small = colBlue;
		}
	}
	else
	{
		if (colGreen < colBlue)
		{
			small = colGreen;
		}
		else
		{
			small = colBlue;
		}
	}

	return small;
}

#if DEBUG
ull get_draw_cnt_brute(ull colRed,
				 ull colGreen,
				 ull colBlue,
				 ull k)
{
	ull num_cnt = 0, numValid = 0;
	ull numRed = 0, numGreen = 0, numBlue = 0;
	ull smallest, numSimilar = 0;
	if (k == 1)
	{
		return 1;
	}
	else
	{
		if ((colRed > k) && (colGreen > k) && (colBlue > k))
		{
			return ((k - 1) * NUM_COL) + 1;
		}
	}

	do 
	{
		if (colRed)
		{
			colRed--;
			numRed++;
			num_cnt++;
//			printf("colRed:%llu numRed:%llu num_cnt:%llu\n",colRed, numRed, num_cnt );
			if (numRed == k)
			{
				break;
			}

		}
		if (colGreen)
		{
			colGreen--;
			num_cnt++;
			numGreen++;
//			printf("colGreen:%llu numGreen:%llu num_cnt:%llu\n",colGreen, numGreen, num_cnt );
			if (numGreen == k)
			{
				break;
			}
			
		}
		if (colBlue)
		{
			colBlue--;
			num_cnt++;
			numBlue++;
//			printf("colBlue:%llu numBlue:%llu num_cnt:%llu\n",colBlue, numBlue, num_cnt );
			if (numBlue == k)
			{
				break;
			}
		}

	}while((numRed != k) || (numGreen != k) || (numBlue != k));

	return num_cnt;
}
#endif

ull get_draw_cnt(ull colRed,
				 ull colGreen,
				 ull colBlue,
				 ull k)
{
	ull num_cnt = 0, numValid = 0;
	ull numRed = 0, numGreen = 0, numBlue = 0;
	ull smallest, numSimilar = 0;
	ull originalk = k;
	if (k == 1)
	{
		return 1;
	}
	else
	{
		if ((colRed >= k) && (colGreen >= k) && (colBlue >= k))
		{
			return ((k - 1) * NUM_COL) + 1;
		}
	}

	do 
	{
		smallest = get_smallest(colRed, colGreen, colBlue, &numValid);
		if (smallest >= k)
		{
			num_cnt += (((k -1)*numValid) + 1);
			numSimilar += k;
			break;
		}
		else 
		{
			num_cnt += (smallest * numValid);
			numSimilar += smallest;
			k -= smallest;
		}
		if (colRed)
		{
			colRed -= smallest;
		}
		if (colGreen)
		{
			colGreen -= smallest;
		}
		if (colBlue)
		{
			colBlue -= smallest;
		}
	}while (num_valid_bags(colRed, colGreen, colBlue) > 1);

	if (numSimilar < originalk)
	{
		num_cnt += (originalk - numSimilar);
	}

	return num_cnt ;
}

#if DEBUG
ull get_max(ull colRed,
			ull colGreen,
			ull colBlue)
{
	ull largest = 0;

	if (colRed > colGreen)
	{
		if (colRed > colBlue)
		{
			largest = colRed;
		}
		else
		{
			largest = colRed;
		}
	}
	else
	{
		if (colGreen > colBlue)
		{
			largest = colGreen;
		}
		else
		{
			largest = colBlue;
		}
	}

	return largest;
}
#endif

int main()
{
	ull t = 0, colRed = 0, colGreen = 0, colBlue = 0, k = 0;

#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<t<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
#if DEBUG
		colRed = (rand()%10)+1;
		colGreen = (rand()%10)+1;
		colBlue = (rand()%10)+1;
		cout << colRed << " "<<colGreen<<" "<<colBlue<<" "<<endl;
		k = (rand()%(get_max(colRed, colGreen, colBlue)))+1;
		cout << k <<endl;
#else 
		cin >> colRed >> colGreen >> colBlue;
		cin >> k;
#endif

#if DEBUG
		ull brute = get_draw_cnt_brute(colRed, colGreen, colBlue, k);
		ull non_brute = get_draw_cnt(colRed, colGreen, colBlue, k);
		if (brute != non_brute)
		{
			cout << "Brute: "<<brute<<"  "<<"Non Brute: "<<non_brute<<endl;
		}
#endif
		cout <<get_draw_cnt(colRed, colGreen, colBlue, k) << endl;
	}

	return 0;
}