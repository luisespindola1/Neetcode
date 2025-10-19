typedef struct pilhano{
    char valor;
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

void empilha(Pilha* p, int val){
    PilhaNo* ptr;
    ptr = (PilhaNo*) malloc(sizeof(PilhaNo));
    ptr->valor = val;
    ptr->next = p->head;

    p->head = ptr;
}

void desempilha(Pilha* p){
    PilhaNo* trav;
    trav = p->head;

    p->head = trav->next;
    free(trav);
}


bool isValid(char* s) {
    Pilha* p = cria();

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == ')'){
            if(p->head == NULL || p->head->valor != '(') return false;
            desempilha(p); //desempilha o (
        }
        else if(s[i] == '}'){
            if(p->head == NULL || p->head->valor != '{') return false;
            desempilha(p);
        }
        else if(s[i] == ']'){
            if(p->head == NULL || p->head->valor != '[') return false;
            desempilha(p);
        }
        else if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            empilha(p, s[i]);
        }
    }

    if(p->head != NULL) return false;

    return true;
}