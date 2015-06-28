int size = 3;
int target = 4;

table = (int **)malloc(sizeof(int*) * (size + 1));
for (i = 0; i <= size; i++) {
	table[i] = (int *)malloc(sizeof(int) * (target + 1));
	table[i][0] = 1;
}
