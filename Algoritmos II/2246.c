#include <stdio.h>
#define maxsize 200
#define passou -1

int search_seqSize(int mosaico[][maxsize], int i, int j, int h, int l, int cor) {
    if (i < 0 || i >= h) {
        return 0;
    }

    if (j < 0 || j >= l) {
        return 0;
    }

    if (mosaico[i][j] == cor) {
        mosaico[i][j] = passou;

        return 1
            + search_seqSize(mosaico, i + 1, j, h, j, cor)
            + search_seqSize(mosaico, i - 1, j, h, j, cor)
            + search_seqSize(mosaico, i, j + 1, h, j, cor)
            + search_seqSize(mosaico, i, j - 1, h, j, cor);
    }

    return 0;
}

int main(){
	
	int h, l, i, j, seqSize, smolseqSize;
	int mosaico[maxsize][maxsize];
	
	scanf("%d %d", &h, &l);
	
	for(i=0;i<h;i++){
		for(j=0;j<l;j++){
			scanf("%d", &mosaico[i][j]);
		}
	}
	
	for(i=0;i<h;i++){
		for(j=0;j<l;j++){
			
			if(mosaico[i][j]!=passou){
				
				seqSize = search_seqSize(mosaico, i, j, h, l, mosaico[i][j]);
				
				if(smolseqSize==-1 || seqSize<smolseqSize){
					smolseqSize==seqSize;
					
					if(smolseqSize==1){
						goto PRINT; 
					}
				}
				
			}
			
		}
	}
	
	PRINT:
		
		printf("%d\n", smolseqSize);
	
	return 0;
}