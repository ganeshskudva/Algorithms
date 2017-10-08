#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <numeric>
#include <map>
using namespace std;

struct point
{
	double x,y;
};

struct triangle
{
	point a,b,c;
	//notes: we use the determinant-area formulation to get the area from the coordinates of the vertexes
	double area(triangle t)
	{
		return fabs((t.a.x*(t.b.y-t.c.y) - t.a.y*(t.b.x-t.c.x) + t.b.x*t.c.y-t.c.x*t.b.y)*0.500000);
	}
};


int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<triangle> v(N);
	vector<double> Areas(N);
	map<double,int> m; //we use a map to keep track of the indexes of the triangles after sorting the vector of areas
	int t = 0;
	while(t < N)
	{
		cin >> v[t].a.x >> v[t].a.y >> v[t].b.x >> v[t].b.y >> v[t].c.x >> v[t].c.y;
		Areas[t] = v[t].area(v[t]);
		m[Areas[t]] = t+1;
		t++;
	}
	sort(Areas.begin(), Areas.end());
	cout << m[Areas[0]] << " " << m[Areas[Areas.size()-1]] << endl;
	return 0;
}
