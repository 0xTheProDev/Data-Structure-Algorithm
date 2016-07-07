#include <stdio.h>

int max(int n, int A[n], int i, int j)
{
    if (i == j)
        return A[i];
    int k = (i + j) / 2;
    int max_1 = max(n, A, i, k);
    int max_2 = max(n, A, k + 1, j);
    return max_1 > max_2 ? max_1 : max_2;
}

int main(void) {
	int N;
	scanf("%d", &N);
	int A[N], i;
	for(i = 0; i < N; i++) 
	    scanf("%d", &A[i]);
	int MAX = max(N, A, 0, N - 1);
	printf("MAX = %d\n", MAX);
	return 0;
}

