                                                                     
                                                                     
                                                                     
                                             
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;


const int MAXN = 1000010;
const int MAXK = 1000010;

int d[MAXN];

multiset<int> l;


bool cmp (int i, int j) {
	return (i>j);
}


int main()
{
	int n, k; scanf ("%d%d", &n, &k);
	for (int i = 0; i < n; i ++){
		scanf ("%d", &d[i]);
	}
	for (int i = 0; i < k; i ++){
		int tmp;  scanf ("%d", &tmp);
		l.insert (tmp);
	}

	std::sort (d, d+n, cmp);

	int answer = 0;
	for (int i = 0; i < n; i ++)
	{
		int current = d[i];
		multiset<int>::iterator it = l.lower_bound (5*current);

		if (it != l.end()){
			answer ++;
			l.erase (it);
			continue;
		}

		multiset<int>::iterator it1 = l.lower_bound (3*current);

		if (it1 == l.end()){
			answer = -1;
			break;
		}
		l.erase (it1);

		multiset<int>::iterator it2 = l.lower_bound (2*current);

		if (it2 == l.end()){
			answer = -1;
			break;
		}
		l.erase (it2);
		answer += 2;
	}

	if (answer == -1){
		puts ("NIE");
	}
	else{
		printf ("%d\n", answer);
	}

	getchar(); getchar();
	return 0;
}
