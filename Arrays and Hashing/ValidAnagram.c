int comp(const void* a, const void* b) {
    return *(const char*)a - *(const char*)b;
}



bool isAnagram(char* s, char* t) {

    int tamanho_s = strlen(s);
    int tamanho_t = strlen(t);

    if(tamanho_t != tamanho_s) return false;

    qsort(s, tamanho_s, sizeof(char), comp);

    qsort(t, tamanho_t, sizeof(char), comp);

    for(int i = 0; *(s + i) != '\0'; i++){
        if(*(s + i) != *(t + i)) return false;
    }

    return true;
}