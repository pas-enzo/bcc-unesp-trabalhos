#include <stdio.h>
#define max 15

int main(){
	
	int n, mat[max][max];
	int i, j, init, k;
	
	do{
		
		scanf("%d", &n);
		
		k=1;
		
		for(i=0;i<n;i++){
			init=k;
			for(j=0;j<n;j++){
				mat[i][j]=init;
				init+=init;
				}k+=k;
			}
		
		
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(n==1){
					printf("%d", mat[i][j]);
				}
					else if(n==2){
							if(j==0)printf("%d", mat[i][j]);
								else printf(" %d", mat[i][j]);
					}
					
						else if(n==3 || n==4){
								if(j==0)printf(" %d", mat[i][j]);
									else printf("%3d", mat[i][j]);
						}
						
							else if(n==5){
									if(j==0)printf("%3d", mat[i][j]);
										else printf("%4d", mat[i][j]);
							}
							
								else if(n==6 || n==7){
										if(j==0)printf("%4d", mat[i][j]);
											else printf("%5d", mat[i][j]);
								}
								
										else if(n==8 || n==9){
												if(j==0)printf("%5d", mat[i][j]);
													else printf("%6d", mat[i][j]);
										}
										
												else if(n==10){
														if(j==0)printf("%6d", mat[i][j]);
															else printf("%7d", mat[i][j]);
												}
												
														else if(n==11 || n==12){
																if(j==0)printf("7%d", mat[i][j]);
																	else printf("%8d", mat[i][j]);
														}
														
																else if(n==13 || n==14){
																		if(j==0)printf("%8d", mat[i][j]);
																			else printf("%9d", mat[i][j]);
																}
														
																		else if(n==15){
																				if(j==0)printf("%9d", mat[i][j]);
																					else printf("%10d", mat[i][j]);
																		}
										
										
			}printf("\n");
		}printf("\n");
		
		
	}while(n!=0);
	
	return 0;
}
