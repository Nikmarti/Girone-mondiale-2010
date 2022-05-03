#include <stdlib.h>
#include <stdio.h>
#define N 12
#define S 4

int main()
{
	void swap(int *a, int *b);
	char punteggio;
	int i;
	int classifica[S] = {0, 0, 0, 0};
	int posizione[S] = {0, 1, 2, 3};
	
	typedef char string[20];
	string squadra[S] = {"ITALIA", "PARAGUAY", "NUOVA ZELANDA", "SLOVACCHIA"};

	
	int giornate[N]= 
	{
		0,1, 2,3,
	  	3,1, 0,2,
	  	3,0, 1,2
	};
	
	i=0;
	while(i<N-1)
	{
		if(i%S==0)
		{
			printf("Giornata %d\n", i/S+1);
		}
		
		printf("%s - %s\n", squadra[giornate[i]],squadra[giornate[i+1]]);
		do{
			printf("Inserisci 1 se ha vinto la squadra in casa, x se hanno pareggiato, 2 se ha vinto la squadra ospite\n");
			scanf(" %c", &punteggio);
			if(punteggio=='1')
			{
				printf("Ha vinto la squadra in casa\n");
				classifica[giornate[i]]=classifica[giornate[i]]+3;
			}
			else if(punteggio=='x')
			{
				printf("Hanno pareggiato le due squadre\n");
				classifica[giornate[i]]=classifica[giornate[i]]+1;
				classifica[giornate[i+1]]=classifica[giornate[i+1]]+1;
			}
			else if(punteggio=='2')
			{
				printf("Ha vinto la squadra ospite\n");
				classifica[giornate[i+1]]=classifica[giornate[i+1]]+3;
			}
		}while(punteggio!='1' && punteggio!='x' && punteggio!='2');
		
		printf("\n");		
		i=i+2;
	}

	if(classifica[posizione[0]]<classifica[posizione[1]])
	{
	 	swap(&posizione[0], &posizione[1]);
	}
	if(classifica[posizione[0]]<classifica[posizione[2]])
	{
		swap(&posizione[0], &posizione[2]);
	}
	if(classifica[posizione[0]]<classifica[posizione[3]])
	{
		swap(&posizione[0], &posizione[3]);
	}
	if(classifica[posizione[1]]<classifica[posizione[2]])
	{
		swap(&posizione[1], &posizione[2]);
	}
	if(classifica[posizione[1]]<classifica[posizione[3]])
	{
		swap(&posizione[1], &posizione[3]);
	}
	if(classifica[posizione[2]]<classifica[posizione[3]])
	{
		swap(&posizione[2], &posizione[3]);
	}
	
	for(i=0; i<S; i++)
	{
		printf("%d %s\n", classifica[posizione[i]], squadra[posizione[i]]);
	}
}

void swap(int *a, int *b)
{
	int t;
	
	t=*a;
	*a=*b;
	*b=t;
}
