#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)

void initialize(int N, int G[N][N], int D[N], int B[N])
{
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			G[i][j] = 0;
		D[i] = INF, B[i] = 0;
	}
}

void getgraph(int N, int G[N][N], int E)
{
	int v1, v2, e;
	while(E--){
		scanf("%d %d %d", &v1, &v2, &e);
		v1--, v2--;
		G[v1][v2] = G[v2][v1] = e;
	}
}

void printgraph(int S, int N, int D[N])
{
	int i;
	for(i = 0; i < N; i++)
		if(i ^ S)
			printf("%d ", D[i]);
    putchar('\n');
}

void path(int S, int N, int G[N][N], int D[N], int B[N])
{
	int i, j, min, k;
	D[S] = 0;
	for(i = 0; i < N - 1; i++){
		for(j = 0, min = INF; j < N; j++)
			if(!B[j] && min > D[j])
				min = D[j], k = j;
		B[k] = 1;
		for(j = 0; j < N; j++)
			if(!B[j] && G[k][j])
				D[j] = MIN(D[j], D[k] + G[k][j]);
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--){
		int N, E, S;
		scanf("%d %d", &N, &E);
		int G[N][N], D[N], B[N];
		initialize(N, G, D, B);
		getgraph(N, G, E);
		scanf("%d", &S);
		S--;
		path(S, N, G, D, B);
		printgraph(S, N, D);
	}
	return 0;
}
