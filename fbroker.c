#include "fbroker.h"
#define LECTURA 0
#define ESCRITURA 1


/*
    *  Función que crea un año a partir de un mensaje con formato
    *  Entrada: String con el mensaje con formato
    *  Salida: Puntero a la estructura Year
*/
Year *crearYear(char *String){
    Year *N = (Year*)malloc(sizeof(Year));
    N->freeGames = crearFreeG();
    //printf("El string ingresado es: %s\n", String);
    char *token = strtok(String, ",");
    N->year = atoi(token);
    token = strtok(NULL, ",");
    N->nameExpensive = token;
    token = strtok(NULL, ",");
    N->nameCheap = token;
    token = strtok(NULL, ",");
    N->priceExpensive = atof(token);
    token = strtok(NULL, ",");
    N->priceCheap = atof(token);
    token = strtok(NULL, ",");
    N->priceAcum = atof(token);
    token = strtok(NULL, ","); 
    N->nGames = atoi(token);
    token = strtok(NULL, ","); 
    N->nNotFree = atoi(token);
    token = strtok(NULL, ",");  
    N->nWindows = atof(token);
    token = strtok(NULL, ",");   
    N->nMacOs = atof(token);
    token = strtok(NULL, ",");   
    N->nLinux = atof(token);
    token = strtok(NULL, ",");
    while(token != NULL){
        agregarFreeG(N, token);
        token = strtok(NULL, ",");
    }
    return N;
}
/*
    * Esta funcion crea una lista de juegos gratis
    * Entrada: void
    * Salida: Puntero a la estructura FreeG
*/
FreeG *crearFreeG(){
    FreeG *F = (FreeG*)malloc(sizeof(FreeG));
    F->name = (char *)calloc(256, sizeof(char));
    F->next = NULL;
    return F;
}
/*
    * Esta función crea una lista de juegos gratis con un juego
    * Entrada: Un puntero a un arreglo de caracteres que representa el nombre del juego
    * Retorno: Un puntero a una estructura freeGames
*/
FreeG *crearFreeG2(char *name){
    FreeG *F = (FreeG *)malloc(sizeof(FreeG));
    F->name = (char *)calloc(256, sizeof(char));
    strcpy(F->name, name);
    F->next = NULL;
    return F;
}
/*
    * Esta función añade un juego gratis a un año especifico
    * Entrada: Año al que se le quiere añadir el juego, nombre del juego
    * Retorno: void
*/
void agregarFreeG(Year *Y, char *nombreJ){
    if(Y->freeGames->next == NULL && Y->freeGames->name[0] == '\0'){
        Y->freeGames->name = nombreJ;
    }
    else{
        FreeG *aux = Y->freeGames;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = crearFreeG2(nombreJ);
    }
}
/*
    * Esta función crea una lista de años
    * Entrada: void
    * Retorno: Un puntero a una estructura Year
*/
ListY *crearListY(){
    ListY *L = (ListY*)malloc(sizeof(ListY));
    L->next = NULL;
    return L;
}
/*
    * Esta función crea una lista de años con un año
    * Entrada: Un puntero a una estructura Year
    * Retorno: Un puntero a una estructura ListY
*/
ListY *crearListY2(char *String){
    ListY *L = crearListY();
    char *token = strtok(String, "¿");
    char **array = (char **)calloc(40, sizeof(char *));
    int i = 0;
    while(token != NULL){
        array[i] = token;
        token = strtok(NULL, "¿");
        i++;
    }
    for(int j = 0; j < i; j++){
        agregarYear(L, crearYear(array[j]));
    }
    return L;
}
/*

*/
void agregarListYear(ListY *L, char *String){
    char *token = strtok(String, "¿");
    char **array = (char **)calloc(40, sizeof(char *));
    int i = 0;
    while(token != NULL){
        array[i] = token;
        printf("%s\n", token);
        token = strtok(NULL, "¿");
        i++;
    }
    for(int j = 0; j < i; j++){
        agregarYear(L, crearYear(array[j]));
    }
}
/*
    * Esta función añade un año a una lista de años
    * Entrada: Lista de años, año a añadir
    * Retorno: void
*/
void agregarYear(ListY *L, Year *Y){
    bool existe = false;
    if(L->year == NULL && L->next == NULL){
        L->year = copiarYear(Y);
    }else{
        ListY *aux = L;
        while(aux->next != NULL){
            if(aux->year->year == Y->year){
                existe = true;
                compararYear(aux->year, Y);
            }
            aux = aux->next;
        }
        if(aux->year->year == Y->year){
            existe = true;
            compararYear(aux->year, Y);
        }
        if(!existe){
            aux->next = crearListY();
            aux->next->year = Y;
        }
    }
}
/*
*/
Year *copiarYear(Year *Y){
    Year *N = (Year*)malloc(sizeof(Year));
    N->freeGames = crearFreeG();
    N->year = Y->year;
    N->nameExpensive = Y->nameExpensive;
    N->nameCheap = Y->nameCheap;
    N->priceExpensive = Y->priceExpensive;
    N->priceCheap = Y->priceCheap;
    N->priceAcum = Y->priceAcum;
    N->nGames = Y->nGames;
    N->nNotFree = Y->nNotFree;
    N->nWindows = Y->nWindows;
    N->nMacOs = Y->nMacOs;
    N->nLinux = Y->nLinux;
    FreeG *aux = Y->freeGames;
    while(aux->next != NULL){
        agregarFreeG(N, aux->name);
        aux = aux->next;
    }
    agregarFreeG(N, aux->name);
    return N;
}
/*
    * Esta función compara dos años y actualiza los datos del año que ya existe
    * Entrada: Año que ya existe, año que se quiere comparar
    * Retorno: void
*/
void compararYear(Year *Y1, Year *Y2){
    if(Y1->priceExpensive < Y2->priceExpensive){
        Y1->priceExpensive = Y2->priceExpensive;
        Y1->nameExpensive = Y2->nameExpensive;
    }
    if(Y1->priceCheap > Y2->priceCheap){
        Y1->priceCheap = Y2->priceCheap;
        Y1->nameCheap = Y2->nameCheap;
    }
    Y1->priceAcum += Y2->priceAcum;
    Y1->nGames += Y2->nGames;
    Y1->nNotFree += Y2->nNotFree;
    Y1->nWindows += Y2->nWindows;
    Y1->nMacOs += Y2->nMacOs;
    Y1->nLinux += Y2->nLinux;
    FreeG *aux = Y2->freeGames;
    while(aux->next != NULL){
        agregarFreeG(Y1, aux->name);
        aux = aux->next;
    }
    agregarFreeG(Y1, aux->name);
}
/*
*/
void ImprimirYear(Year *Y){
    printf("El año es: %d\n", Y->year);
    printf("El juego más caro es: %s\n", Y->nameExpensive);
    printf("El precio del juego más caro es: %f\n", Y->priceExpensive);
    printf("El juego más barato es: %s\n", Y->nameCheap);
    printf("El precio del juego más barato es: %f\n", Y->priceCheap);
    printf("El precio acumulado es: %f\n", Y->priceAcum);
    printf("La cantidad de juegos es: %d\n", Y->nGames);
    printf("La cantidad de juegos no gratis es: %d\n", Y->nNotFree);
    printf("Los juegos de Windows son: %f\n", Y->nWindows);
    printf("Los juegos de MacOs son: %f\n", Y->nMacOs);
    printf("Los juegos de Linux son: %f\n", Y->nLinux);
    FreeG *aux = Y->freeGames;
    while(aux != NULL){
        printf("Los juegos gratis son: \n%s\n", aux->name);
        aux = aux->next;
    }
}
/*
    * Esta función obtiene los años de un archivo
    * Entrada: Recibe un Broker (el cual contiene el archivo a abrir)
    * Salida: Retorna un arreglo de enteros con los años
*/
int* obtenerAnios(Broker *B){
    FILE *fp;
    fp = fopen(B->entrada, "r");
    int *anios = (int*)calloc(100, sizeof(int)), i = 0, anio;
    char linea[256];
    while(fgets(linea, 256, fp)){
        int largo = strlen(linea);
        int anio = obtenerAnio(linea, largo - 1);
        float precio_juego = obtenerPrecio(linea, largo);
        if(buscarAnio(anio, anios) == -1 
            && anio >= B->anio 
            && (precio_juego >= B->precio_minimo || precio_juego == 0.0)){
            anios[i] = anio;
            i++;
        }
        memset(linea, 0, 256);
    }
    int *anios_correctos = (int*)malloc(i * sizeof(int));    
    for(int j=0; j < i; j++){
        anios_correctos[j] = anios[j];
    }
    qsort(anios_correctos, i, sizeof(int), ordenarAnios);
    fclose(fp);
    B->n_anios = i;
    B->anio = anios_correctos[0];
    //printf("El anio ahora es: %d\n", B->anio);
    return anios_correctos;
}
/*
    * Esta funcion ordena un array de años
    * Entrada: Recibe un arreglo de enteros con los años
    * Salida: Retorna un arreglo de enteros con los años ordenados
*/
int ordenarAnios(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
/*
    * Esta función obtiene los años de cada juego del archivo de entrada
    * Entrada: Recibe la linea a evaluar, y el largo de la línea
    * Salida: Retorna el año del juego
*/
int obtenerAnio(char linea[], int largo){
    int comas = 0;
    while(comas != 5){
        if(linea[largo] == ','){
            comas++;
        }
        largo--;
    }
    char anio[4] = {linea[largo + 2], linea[largo + 3],
    linea[largo + 4], linea[largo + 5]};
    return atoi(anio);
}
/*
    * Esta función obtiene el precio de un juego de 
    * una linea de texto (array de caracteres)
    * Entrada: Recibe la linea a evaluar, y el largo de la línea
    * Salida: Retorna el precio del juego
*/
float obtenerPrecio(char linea[], int largo){
    int comas = 0, i = 0;
    while(comas != 7){
        if(linea[largo] == ','){
            comas++;
        }
        largo--;
    }
    int pos = largo + 2;
    while(linea[pos + i] != ','){
        i++;
    }
    char precio_[i];
    for(int j=0; j < i; j++){
        precio_[j] = linea[pos + j];
    }
    return atof(precio_);
}
/*
    * Esta función verifica si un año ya fue agregado
    * Entrada: Recibe el año a evaluar y el arreglo de años
    * Salida: Retorna la posición del año en el arreglo, si no lo encuentra retorna -1
*/
int buscarAnio(int anio_, int *anios){
    for(int j=0; j < 100; j++){
        if(anios[j] == anio_){
            return j;
        }
    }
    return -1;
}
/*
    * Esta función crea un broker que almacenará los datos de entrada
    * Entrada: Recibe el nombre del archivo de entrada, el nombre del archivo
    * de salida, el año a evaluar, el precio mínimo a evaluar, el número de workers
    * y una bandera booleana.
    * Returno: Retorna un Broker

*/
Broker* crearBroker(char input_[], char output_[], int year_, float minimun_price_, bool show_, int n_workers_){
    Broker *B;
    B = (Broker*)malloc(sizeof(Broker));
    strncpy(B->entrada, input_, 100);
    strncpy(B->salida, output_, 100);
    B->anio = year_;
    B->precio_minimo = minimun_price_;
    B->mostrar = show_;
    B->n_anios = 0;
    B->n_workers = n_workers_;
    return B;
}
/*
*/
void Ejecutar(Broker *B){
    srand(time(NULL));
    char mensaje[5000];
    char receptor[5000];
    int fd1[B->n_workers][2], fd2[B->n_workers][2];
    for(int i=0; i < B->n_workers; i++){
        pipe(fd1[i]);
        pipe(fd2[i]);
    }
    int idChild = 0;
    int pid;
    int pipes[B->n_workers];
    while(idChild < B->n_workers){
        pid = fork();
        pipes[idChild] = pid;
        if(pid == 0){
            break;
        }
        idChild++;
    }
    if(pid == 0){
        close(fd2[idChild][LECTURA]);
        dup2(fd2[idChild][ESCRITURA], STDOUT_FILENO);
        close(fd2[idChild][ESCRITURA]);
        close(fd1[idChild][ESCRITURA]);
        dup2(fd1[idChild][LECTURA], STDIN_FILENO);
        close(fd1[idChild][LECTURA]);
        execl("./worker", "./worker", NULL);
        perror("Error en el execl");
        exit(EXIT_FAILURE);
    }else{
        for(int i=0; i < B->n_workers; i++){
            close(fd1[i][LECTURA]);
        }
        int random;
        char linea[500];
        char mensaje[5000];
        FILE *fp = fopen(B->entrada, "r");
        FILE *fp2 = fopen(B->salida, "a");
        int k = 1;
        while(fgets(linea, 500, fp) != NULL){
            random = rand() % (B->n_workers);
            int largo = strlen(linea);
            int anio_ = obtenerAnio(linea, largo - 1);
            float precio_juego = obtenerPrecio(linea, largo);
            if(anio_ >= B->anio && (precio_juego >= B->precio_minimo || precio_juego  == 0.0)){
                strcpy(mensaje, linea);
                printf("La línea %d es: %s", k, mensaje);
                write(fd1[random][ESCRITURA], mensaje, strlen(mensaje));
            }
            k++;
        }
        fclose(fp);
        for(int i=0; i < B->n_workers; i++){
            write(fd1[i][ESCRITURA], "FIN", 4);
        }
        //while(true);
        ListY *L = crearListY();
        char recibido[5000];
        char recibido_aux[5000];
        for(int i=0; i < B->n_workers; i++){
            read(fd2[i][LECTURA], recibido, 5000);
            strcpy(recibido_aux, recibido);
            agregarYear(L, crearYear(recibido_aux));
        }
        fclose(fp2);
    }
}
