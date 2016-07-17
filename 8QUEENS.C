/*
	8 QUEENS ARE PLACED IN 8 X 8 CHESSBOARD SUCH THAT THEY
	CAN'T ELIMINATE EACH OTHER, PROVIDED A QUEEN IS AT (a, b)
*/

#include <stdio.h>
#include <string.h>

// RETURNS ABSOLUTE VALUE INSIDE PARENTHESIS
#define abs(X) ((X) > 0 ? (X) : -(X))

int x[9], T, a, b, Count;

int place(int, int);
void NQ(int);

int main(void){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &a, &b);
		memset(x, 0, sizeof(x));
		printf("\nSOLN				 COLUMN\n");
		printf(" # 			1  2  3  4  5  6  7  8\n\n");
		NQ(1);
		putchar('\n');
	}
	return 0;
}

/*
	FUNCTION THAT TAKES ONE ARGUMENT AND RETURNS NOTHING
	ARGUMENT [INT] : NUMBER OF QUEEN TO BE PLACED
	RECURSIVE : YES
	PLACES THE QUEEN IN A PARTICULAR ROW AND COLUMN
	AND PRINTS THE DETAILS WHEN 8th QUEEN IS PLACED
*/
void NQ(int queen)
{
	for(int row = 1; row <= 8; row++)
		if(place(queen, row)){
			x[queen] = row;
			if(queen == 8 && x[b] == a){
				printf("%2d 			%d", ++Count, x[1]);
				for(int j = 2; j <= 8 || !putchar('\n'); j++)
					printf("  %d", x[j]);
			}
			else
				NQ(queen + 1);
		}
}

/*
	FUNCTION THAT TAKES TWO ARGUMENT AND RETURNS AN INTEGER
	ARGUMENT 1 [INT] : NUMBER OF QUEEN
	ARGUMENT 2 [INT] : NUMBER OF ROW
	RECURSIVE : NO
	TAKES A QUEEN AND CHECKS WHETHER IT IS POSSIBLE TO PLACE
	IT IN THE ROW WITHOUT ELIMINATING PREVIOUS QUEENS PLACED
	IN SAME COLUMN OR DIAGONAL
	RETURN [INT] : 1 (IF POSSIBLE) or 0 (IF NOT)
*/
int place(int queen, int row)
{
	for(int prev = 1; prev < queen; prev++)
		if(x[prev] == row || abs(x[prev] - row) == abs(prev - queen))
			return 0;
	return 1;
}
