/*
  SHORTEST PATH BETWEEN TWO VERTICES OF A GIVEN GRAPH BY DIJKSTRA'S ALGORITHM
  
  DATA-STRUCTURE : MATRIX (2D ARRAY), ARRAY
  ALGORITHM : DIJKSTRA'S ALGORITHM
  SPACE COMPLEXITY : O (N² + N + N)
  TIME COMPLEXITY : O (N²) or O (N)
*/

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MIN(X, Y) (X) < (Y) ? (X) : (Y)
#define SIZE 10
#define INFINITY INT_MAX
#define INIT 0
#define FINAL 6

int G[SIZE][SIZE] = {0}, A[SIZE], B[SIZE], N, E;

inline void init(void)
{
	register int i = 0;
	while(i < N){
		A[i] = INFINITY, B[i] = false;
		i++;
	}
	A[INIT] = 0, B[INIT] = true;
}

void getGraph(void)
{
	int v1, v2, e, i = 0;
	while(i < E){
		scanf("%d %d %d", &v1, &v2, &e);
		assert(v1 >= 0 && v1 < N);
		assert(v2 >= 0 && v2 < N);
		G[v1][v2] = G[v2][v1] = e;
		i++;
	}
}

int path(int start, int finish)
{
	if(start == finish)
		return A[finish];
	int min = INT_MAX, i, k = 0;
	for(i = 0; i < N; i++){
		if(G[start][i] && !B[i]){
			A[i] = MIN(A[i], A[start] + G[start][i]);
			if(min > A[i]) k = i, min = A[i];
		}
	}
	B[k] = true;
	return path(k, finish);
}

int main(void) {
	scanf("%d %d", &N, &E);
	assert(N > 0 && N <= SIZE);
	getGraph();
	init();
	int dist = path(INIT, FINAL);
	printf("MINIMUM DISTANCE BETWEEN %d and %d is %d\n", INIT, FINAL, dist);
	return 0;
}
