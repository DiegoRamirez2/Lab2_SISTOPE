





/*
    * Esta función convierte un string a una lista de años, funcionará
    * como "desencriptador" para recibir mensajes entre procesos.
    * Entrada: String con los datos de la lista de años.
    * Retorno: Lista de años.
*/
LA *convertirAlista(char *string){
    LA *L = crearLA();
    char *token = strtok(string, "¿");
    // /*
    int i = 0;
    while(token != NULL){
        agregarAnio()
        //L = crearLA2(A);
        token = strtok(NULL, "¿");
    // */
    }
    printf("I es: %d\n", i);
    return L;
}

char *AnioAstring(char *string){
        char *token2 = strtok(string, ",");
        printf("El token 2 es: %s\n", token2);
        //Anio *A = (Anio*)malloc(sizeof(Anio));
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //strcpy(A->expensiveGame, token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //strcpy(A->cheapGame, token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);  
        //A->cheapPrice = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->expensivePrice = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->priceAcum = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nGames = atoi(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nWindows = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nMacOs = atof(token2);
        token2 = strtok(NULL, ",");
        printf("El token 2 es: %s\n", token2);
        //A->nLinux = atof(token2);
        token2= strtok(NULL, ",");
        i++;
        while(token2 != NULL){
            printf("El token 3 es: %s\n", token2);
            //A->freeGames = crearFG(token3, strlen(token3));
            token2 = strtok(NULL, ",");
        }
}