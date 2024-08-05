#include <stdio.h>
#include <stdlib.h>
#define MAX 100100

typedef struct{
	
	unsigned id;
	unsigned volume;
	
} presente;


int compara(presente *, presente *);

int compara2(unsigned *, unsigned *);

	presente presentes[MAX] = { 0 };
	unsigned ids[MAX];


void main () {
	
	unsigned i;
	unsigned numNoel, numBruno;
	unsigned short ndecasos;
	unsigned short hei, wid, len;
	
	scanf("%hu", &ndecasos);
	
	while (ndecasos--) {
	
		scanf("%u %u", &numNoel, &numBruno);

			for (i=0; i<numNoel; i++) {

				scanf("%u %hu %hu %hu", &presentes[i].id, &hei, &wid, &len);
				presentes[i].volume = hei * wid * len;

			}
			
		qsort(presentes, numNoel, sizeof(presente), compara);

		for (i=0; i<numBruno; i++)
			ids[i] = presentes[i].id;

		qsort(ids, numBruno, sizeof(unsigned), compara2);
		
		for (i=0; i<numBruno; i++) {

			if (i!=0 && i!=numBruno)
				printf(" ");

			printf("%u", ids[i]);

		}

		printf("\n");
		
	}
	
}

int compara(presente *a, presente *b)
{

	if (a->volume == b->volume)
	{

		if (a->id > b->id)
			return 1;
		else
			return -1;

	}
	else if (a->volume > b->volume)
		return -1;
	else
		return 1;

}

int compara2(unsigned *a, unsigned *b)
{

	if (*a > *b)
		return 1;
	else
		return -1;

}