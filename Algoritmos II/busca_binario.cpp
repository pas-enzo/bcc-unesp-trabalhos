#include <stdio.h>
#include <stl.h>
#include <iostream>
#include <vector>
#define MAX 100
 












int main(){
	
	
	int n;
	vector <int> vetor[MAX];
	
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
		scanf("%d", &vetor[i]);
		
	sort(vetor.begin(), vetor.end());
	
	for( i=0;i<n;i++)
		printf("%d", &vetor[i]);
	
	return 0;
}