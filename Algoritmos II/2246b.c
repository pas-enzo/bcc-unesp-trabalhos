#include <stdio.h>

#define maxsize 200
#define PASSOU -1

int find_seqSize(int mosaico[][maxsize], int i, int j, int h, int l, int cor) {
    if(i<0 || i>=h){
        return 0;
    }

    if(j<0 || j>=l){
        return 0;
    }

    if (mosaico[i][j]==cor) {
        mosaico[i][j]=PASSOU;

        return 1
            + find_seqSize(mosaico, i + 1, j, h, l, cor)
            + find_seqSize(mosaico, i - 1, j, h, l, cor)
            + find_seqSize(mosaico, i, j + 1, h, l, cor)
            + find_seqSize(mosaico, i, j - 1, h, l, cor);
    }

    return 0;
}

int main (void) {
    int mosaico[maxsize][maxsize];
    int seqSize, smolseqSize=-1;
	int h, l, i, j;
    

    scanf("%d %d", &h, &l);

    for(i=0;i<h;i++){
        for(j=0;j<l;j++){
            scanf("%d", &mosaico[i][j]);
        }
    }

    for(i=0;i<h;i++){
        for(j=0;j<l;j++){
            
			
			if(mosaico[i][j]!=PASSOU){
                
				seqSize = find_seqSize(mosaico, i, j, h, l, mosaico[i][j]);

                if (smolseqSize==-1 || seqSize<smolseqSize) {
                    smolseqSize = seqSize;

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
