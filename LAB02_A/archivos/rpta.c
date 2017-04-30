#include<stdio.h>

void imprimir(int x){
	int i;
	char leng[x];
	for(i=0;i<x;i++)
		leng[i]='*';
	for(i=0;i<x;i++)
		printf("%c", leng[i]);
}

int main(){
	int c, i, nwhite,nother;
	int nletras[26];
	nwhite = nother =0;
	for(i=0;i<26;++i)
		nletras[i]=0;
	while((c=getchar())!=EOF)
		if (c>='a' && c<='z')
			++nletras[c-'a'];
		else if(c==' '||c=='\n'||c=='\t')
			++nwhite;
		else
			++nother;
	}
	printf("letras \n");
	for(i=0;i<26;++i){
		imprimir(nletras[i]);
		printf("\n");
	}
	printf(", espacio en blanco: %d, other: %d\n", nwhite, nother);
}

