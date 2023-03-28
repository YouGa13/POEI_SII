#include <stdio.h>
void sumtabs(int* ptr_tab1, int* ptr_tab2, int taille);
void modification(int* ptr_tab1, int* ptr_tab2, int* ptr_tab3, int taille);

#define tailleMax 50

int main() {
	
	int tab1[] = { -1, -2, -3 };
	int tab2[] = { 1, 2 , 3 };
	int tab3[3];

	int tailleDuTableau = sizeof(tab1) / sizeof(int);
	modification(tab1, tab2, tab3, 3);
	sumtabs(tab1, tab2, tailleDuTableau);
	return 0;
}

void operatore(int element1, int element2, int* adressetab3) {
	*adressetab3 = element1 + element2;
}

void modification(int* ptr_tab1, int* ptr_tab2, int* ptr_tab3, int taille){
	for (int i = 0; i < taille; i++) {
		operatore(ptr_tab1[i], ptr_tab2[i], &ptr_tab3[i]);
	}
}
void sumtabs(int* ptr_tab1, int* ptr_tab2, int taille) {
	for (int i = 0; i < taille; i++) {
		ptr_tab1[i] += ptr_tab2[i];
	}
}