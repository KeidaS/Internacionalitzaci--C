#include <stdio.h>
#include <string.h>

#define F 10
#define C 20
#define N 500


void llegir_lab (char lab[F][C]); // llegim el laberint
void llegir (char lab[F][C]); 
void llegir_coordenades (int &f_i, int &c_i); // llegim les coordenades
void imprimir_lab (char lab[F][C]); // acció per imprimir el laberint
void llegir_passes (char passes[N], int &i); // llegim les passes a seguir al laberint
void resultats (int f_1, int c_i, int i, char passes[N], char lab[F][C]); // tractament i mostra de resultats
void ficar_blancs (char lab[F][C]); // acció per cambiar les 'O' per ' '

int main () {

char passes[N];
char lab[F][C];
int i; // nº de passes
int f_i, c_i; // fila inicial, columna inicial

	llegir_lab (lab);
	llegir_coordenades (f_i, c_i);
	llegir_passes (passes, i);
	resultats (f_i, c_i, i, passes, lab);
	
	

}

void llegir_lab (char lab[F][C]) {
	printf ("Introdueix un laberint de %ix%i\n", F, C);
	llegir (lab);
}

void llegir (char lab[F][C]) {
	char c;
	int i, j;
	
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			scanf ("%c", &c);
			if (c!='\n') {
				lab[i][j]=c;
			} else {
				scanf ("%c", &lab[i][j]);
			}
			
		}
	}
}

void imprimir_lab (char lab[F][C]) {
	int i, j;
	for (i=0;i<F; i++) {
		for (j=0;j<C; j++) {
			printf ("%c", lab[i][j]);
		}
		printf ("\n");
	}

}


void llegir_coordenades (int &f_i, int &c_i) {

	printf ("Introdueix les coordenades d'inici\n");
	scanf ("%i %i", &f_i, &c_i);
}

void llegir_passes (char passes[N], int &i) {
	
	char c;
	printf ("Introdueix les passes del recorregut\n");
	
	i=0;

	scanf ("%c", &c);
	scanf ("%c", &c);
	while (i<200 && c!='\n') {
		passes[i]=c;
		i++;
		scanf ("%c", &c);
	}	
}

void resultats (int f_i, int c_i, int i, char passes[N], char lab[F][C]) {
	
	bool ok=true;
	bool final=false;
	int j=0;
	int fil, col;
	
	fil=f_i;
	col=c_i;

	if (lab[f_i][c_i]=='X') {
		ok=false;
	} else {
		lab[f_i][c_i]='i';
	}

	while (ok==true && j<i && final==false) {
	
		if (passes[j]=='n') {
			f_i--;
			if (lab[f_i][c_i]=='O') {
				lab[f_i][c_i]='i';
			} else {
				ok=false;
			}
		} else if (passes[j]=='s') {
			f_i++;
			if (lab[f_i][c_i]=='O') {
				lab[f_i][c_i]='i';
			} else {
				ok=false;
			}
		} else if (passes[j]=='e') {
			c_i++;
			if (lab[f_i][c_i]=='O') {
				lab[f_i][c_i]='i';
			} else {
				ok=false;
			}
		} else if (passes[j]=='o') {
			c_i--;
			if (lab[f_i][c_i]=='O') {
				lab[f_i][c_i]='i';
			} else {
				ok=false;
			}
		}

		if (f_i==0 || f_i==F-1) {
			final=true;
		} else if (c_i==0 || c_i==C-1) {
			final=true;
		}			

		j++;
	}
	
	ficar_blancs (lab);
	imprimir_lab (lab);
	
	printf ("Coordenades d'inici: (%i , %i )\n", fil, col);
	printf ("Passes del recorregut: %s\n", passes);

	if (ok==true && final==false) {
		printf ("La solució al laberint NO es correcta\n");
	}
	
	if (ok==false) {
		printf ("La solució al laberint NO es correcta\n");
	}
	if (final==true) {
		printf ("La solució al laberint es correcta!\n");
	}
	

}

void ficar_blancs (char lab[F][C]) {
	
	int i, j;
	
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			if (lab[i][j]=='O') {
				lab[i][j]=' ';
			}
		}
	}

}
