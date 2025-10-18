bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    for(int i = 0; i < 9; i++){ //checagem das linhas
        for(int j = 0; j < 8; j++){
            for(int k = j + 1; k < 9; k++){
                if(board[i][j] == board[i][k] && board[i][j] != '.'){
                    return false;
                }
            }
        }
    }

    for(int i = 0; i < 9; i++){ //checagem das colunas
        for(int j = 0; j < 8; j++){
            for(int k = j + 1; k < 9; k++){
                if(board[j][i] == board[k][i] && board[j][i] != '.'){
                    return false;
                }
            }
        }
    }


    int coluna_offset = 0;

    while(coluna_offset < 9){
        int linha_offset = 0;

        while(linha_offset < 9){

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(board[linha_offset + i][coluna_offset + j] == '.'){
                        continue;
                    }
                    int equal_flag = 0; //flag pra cada elemento
                    for(int k = i; k < 3; k++){
                        int z = (k == i) ? j + 1 : 0;
                        for(; z < 3; z++){
                            if(board[linha_offset + i][coluna_offset + j] == board[linha_offset + k][coluna_offset + z]){
                                equal_flag++;
                            }
                        }   
                    }
                    
                    if(equal_flag >= 1){
                        return false;
                    }
                }
            }


            linha_offset += 3;
        }

        coluna_offset += 3;
    }

    return true;
}
