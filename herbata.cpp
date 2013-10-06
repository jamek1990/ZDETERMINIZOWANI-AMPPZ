                                                                     
                                                                     
                                                                     
                                             
#include <cstdio>


const int MAXN = 1000010;


int main()
{
	int n; scanf("%d", &n); // printf("WCZYTANO: %d\n", n);
	char buff[MAXN]; scanf("%s", buff); // printf("WCZYTANO: %s\n", buff);

	int amountH = 0;
	int amountM = 0;

	for (int i = 0; i < n - 1; i++){
		(buff[i] == 'M') ? amountM++ : amountH++;
	}


	if (n == 1){
		puts("HM");
	}
	else{
		if (amountH > amountM){
			puts("H");
		}
		if (amountH < amountM){
			puts("M");
		}
		if (amountH == amountM)
		{
			if (buff[n-2] == 'H'){
				puts("M");
			}
			else{
				puts("H");
			}
		}
	}

	getchar(); getchar();
	return 0;
}
