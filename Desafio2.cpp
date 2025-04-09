#include <iostream>
#include <ctime>
using namespace std;

struct no {
	int info;
	no *link;
};

no *inicializaPilha(no *L) {
	return NULL;
}

no *PUSH(no *L, int x){
    no *N;
    N = new no;
    N->info = x;
    N->link = L;
    L=N;
    return(L);
}

no *POP(no *L, int *n) {
	no *AUX;
	if (L != NULL) {
		*n = L->info;
		AUX = L;
		L = L->link;
		delete AUX;
	}
	else{
		*n = 0;
	}
	return (L);
}

void imprimePilha(no *L) {
	no *P;
	P = L;	
	
	printf("\n IMPRIME PILHA: \n");	
	while(P != NULL) {
		cout << P->info << " ";	
		P = P->link;
	}	
}

int geraNum(){
    return rand()%10+1;
}

int main(){
    no *P1;
    no *P2;
    int J1=0, J2=0;
    int aux1, aux2;
    P1 = inicializaPilha(P1); 
    P2 = inicializaPilha(P2);
    srand(time(0));
    for(int i=0; i<10; i++){
        P1 = PUSH(P1, (geraNum()));
        P2 = PUSH(P2, (geraNum()));
    }
    cout << "==============================" << endl; //Mostra pilha pós srand
    imprimePilha(P1);
    cout << endl;
    imprimePilha(P2);
    cout << endl << "==============================" << endl;
    for(int i=0; i<10; i++){
        P1 = POP(P1, &aux1);
        cout << "Jogador 1 retira a carta: " << aux1 << endl;
        P2 = POP(P2, &aux2);
        cout << "Jogador 2 retira a carta: " << aux2 << endl;
        if(aux1 > aux2){
            J1++;
            cout << "Jogador 1 pontuou.\n" << endl;
        }
        else if(aux2 > aux1){
            J2++;
            cout << "Jogador 2 pontuou.\n" << endl;
        }
        else{
            cout << "Empate, ninguem pontuou.\n" << endl;
        }
        
    }
    if(J1 > J2){
        cout << "Jogador 1: " << J1 << " pontos" << endl << "Jogador 2: " << J2 << " pontos" << endl << "Jogador 1 venceu!" << endl;
    }
    else{
        cout << "Jogador 1: " << J1 << " pontos" << endl << "Jogador 2: " << J2 << " pontos" << endl << "Jogador 2 venceu!" << endl;
    }
    cout << "==============================" << endl; //Mostra pilha pós fim do jogo
    imprimePilha(P1);
    cout << endl;
    imprimePilha(P2);
    cout << endl << "==============================" << endl;

}
