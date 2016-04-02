#include <bits/stdc++.h>

typedef long long int ull;

using namespace std;

#define DEBUG 0

#if DEBUG
void gen_random(char *s, const int len) {
//    static const char alphanum[] =
//        "abcdefghijklmnopqrstuvwxyz";
    static const char alphanum[] =
       "RGB";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
}
#endif

void count_color( std::string str, ull *red, ull *green, ull *blue)
{
	ull red_col = 0;
	ull green_col = 0;
	ull blue_col = 0;
	ull i = 0;

	for (i = 0; i < str.length(); i++)
	{	
		if (str[i] == 'R')
		{
			red_col++;
		}
		if (str[i] == 'G')
		{
			green_col++;
		}
		if (str[i] == 'B')
		{
			blue_col++;
		}
	}

	*red = red_col;
	*green = green_col;
	*blue = blue_col;

}

ull get_value(ull n, 
			  ull colRed,
			  ull colGreen,
			  ull colBlue)
{
	ull value = 0;
	ull num_rooms_painted = 0;

	if (colRed > colGreen)
	{
		if (colRed > colBlue)
		{
			num_rooms_painted = n - colRed;
			value = (num_rooms_painted - colGreen) + (num_rooms_painted - colBlue);
		}
		else
		{
			num_rooms_painted = n - colBlue;
			value = (num_rooms_painted - colGreen) + (num_rooms_painted - colRed);
		}
	}
	else
	{
		if (colGreen > colBlue)
		{
			num_rooms_painted = n - colGreen;
			value = (num_rooms_painted - colRed) + (num_rooms_painted - colBlue);
		}
		else 
		{
			num_rooms_painted = n - colBlue;
			value = (num_rooms_painted - colRed) + (num_rooms_painted - colGreen);
		}
	}

	return value;
}

int main()
{
	ull t = 0, n = 0;
	std::string str;
	ull colRed, colGreen, colBlue;
#if DEBUG 
	srand((unsigned)time(0));
	t = (rand()%10)+1; 
	cout <<N<<endl;
#else 
	cin >> t;
#endif 

	while (t--)
	{
#if DEBUG 
		n = (rand()%10)+1;
		cout << n;
		char buff[n];
		memset(buff, '\0', n*sizeof(char));
		gen_random(buff, sizeof(buff));
		str.assign(buff, sizeof(buff));
		cout<<str<<endl;
#else 
		cin >> n;
		cin >> str;
#endif
		count_color(str, &colRed, &colBlue, &colGreen);

		if ((colRed == n) || (colGreen == n) || (colBlue == n))
		{
			cout << "0"<<endl;
		}	
		else
		{
			cout << get_value(n, colRed, colGreen, colBlue) << endl;
		}

	}

	return 0;
}