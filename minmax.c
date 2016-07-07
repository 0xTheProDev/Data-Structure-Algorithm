#include <stdio.h>

typedef struct{
    int min, max;
} mnmx;

mnmx minmax(int n, int A[n], int i, int j)
{
    if (i == j)
        return (mnmx){A[i], A[i]};
    int k = (i + j) / 2;
    mnmx mnmx_1 = minmax(n, A, i, k);
    mnmx mnmx_2 = minmax(n, A, k + 1, j);
    return (mnmx){mnmx_1.min < mnmx_2.min ? mnmx_1.min : mnmx_2.min,
            mnmx_1.max > mnmx_2.max ? mnmx_1.max : mnmx_2.max};
}

int main(void) {
	int N;
	scanf("%d", &N);
	int A[N], i;
	for(i = 0; i < N; i++) 
	    scanf("%d", &A[i]);
	mnmx MNMX = minmax(N, A, 0, N - 1);
	printf("MAX = %d, MIN = %d\n", MNMX.max, MNMX.min);
	return 0;
}

