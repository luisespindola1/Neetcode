

typedef struct pilhano{
    int valor;
    struct pilhano* next;
}PilhaNo;

typedef struct pilha{
    PilhaNo* head;
}Pilha;

Pilha* cria(){
    Pilha* p;
    p = (Pilha*) malloc(sizeof(Pilha));

    p->head = NULL;

    return p;
}

void add(Pilha* p, int val){
    PilhaNo* ptr;
    ptr = (PilhaNo*) malloc(sizeof(PilhaNo));

    ptr->valor = val;
    ptr->next = p->head;

    p->head = ptr;
}

int desempilha(Pilha* p){
    int numero;
    if(p->head != NULL){
        PilhaNo* trav = p->head;
        p->head = trav->next;
        numero = trav->valor;
        free(trav);
    }
    return numero; //garantido que seja uma operacao valida
}

int operation(Pilha* p, char op){
    int resultado;
    int op2 = desempilha(p);
    int op1 = desempilha(p);
    switch(op){
        case '+': resultado = op1 + op2; break;
        case '-': resultado = op1 - op2; break;
        case '*': resultado = op1 * op2; break;
        case '/': resultado = op1 / op2; break;
    }

    return resultado;
}


int evalRPN(char** tokens, int tokensSize) {
    
    Pilha* p = cria();
    for(int i = 0; i < tokensSize; i++){
        int num;
        if(tokens[i][0] == '+' || (tokens[i][0] == '-' && strlen(tokens[i]) == 1) || tokens[i][0] == '*' || tokens[i][0] == '/'){
            num = operation(p, tokens[i][0]); //desempilha os dois ultimos numeros e realiza operacao
        }
        else{
            sscanf(tokens[i], "%d", &num); //transforma string pra inteiro
        }

        add(p, num); //empilha novo numero ou resultado de uma operacao
    }

    return p->head->valor; //resultado da conta
}