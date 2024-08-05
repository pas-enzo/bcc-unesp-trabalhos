#include <stdio.h>


int main() {

	int N, hor, horseg, min, seg;

	horseg = 3600;

	scanf("%i", &N);

	hor = (N / horseg);

	min = (N - (horseg * hor)) / 60;

	seg = (N - (horseg * hor) - (min * 60));

	printf("%i:%i:%i\n", hor, min, seg);
	
	return 0;
}
