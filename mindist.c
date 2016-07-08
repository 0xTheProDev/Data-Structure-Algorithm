#include <stdio.h>
#include <limits.h>
#define MAX 10
#define INIT 1
#define FINAL N

int A[MAX][MAX] = {0}, N, E;

int path(int init, int final)
{
	if(init == final)
		return 0;
	int i, p, temp = 0, min = INT_MAX;
	for(i = 0; i < N; i++)
		if((temp = A[init][i])){
			A[init][i] = A[i][init] = 0;
			p = temp + path(i, final);
			if(p < min) min = p;
			A[init][i] = A[i][init] = temp;
		}
	return min;
}

int main(void) {
	int i, v1, v2, e, dist;
	scanf("%d %d", &N, &E);
	for(i = 0; i < E; i++){
		scanf("%d %d %d", &v1, &v2, &e);
		if(v1 ^ v2)
			A[v1 - 1][v2 - 1] = A[v2 - 1][v1 - 1] = e;
	}
	dist = path(INIT - 1, FINAL - 1);
	if(dist ^ INT_MAX)
		printf("MINIMUM DISTANCE BETWEEN %d and %d is %d\n", INIT, FINAL, dist);
	return 0;
}
