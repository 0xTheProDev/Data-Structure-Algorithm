/*
  To Find the Maximum and Next Maximum of N given Numbers.
  
  Data-Structure : Array
  Algorithm : Divide and Conquer
  Space Complexity : O (N)
  Time Complexity : O (log N)
*/

#include <stdio.h>
#include <limits.h>

typedef struct{
    int max, next;
} nxmx;

nxmx nexmax(int n, int A[n], int i, int j)
{
    if (i == j)
        return (nxmx){A[i], INT_MIN};
    int k = (i + j) / 2, d;
    nxmx nxmx_a[] = {nexmax(n, A, i, k), nexmax(n, A, k + 1, j)};
    return (nxmx){nxmx_a[d = nxmx_a[1].max > nxmx_a[0].max].max, 
    		nxmx_a[d].next > nxmx_a[!d].max ? nxmx_a[d].next : nxmx_a[!d].max};
}

int main(void) {
	int N;
	scanf("%d", &N);
	int A[N], i;
	for(i = 0; i < N; i++) 
	    scanf("%d", &A[i]);
	nxmx NXMX = nexmax(N, A, 0, N - 1);
	printf("MAX = %d, NEXTMAX = %d\n", NXMX.max, NXMX.next);
	return 0;
}
