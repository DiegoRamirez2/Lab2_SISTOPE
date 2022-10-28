#include "Padre.h"
/*
    * Esta función crea un padre que contiene el documento que se leerá, 
    * el documento que se escribirá, el año desde el cual se filtrará, 
    * el precio mínimo que se filtrará y si se mostrará o no por consola
    * Entrada: No recibe parametros
    * Salida: Retorna un padre
*/
Padre* crearPadre(char input_[], char output_[], int year_, float minimun_price_, bool show_){
    Padre *P;
    P = (Padre*)malloc(sizeof(Padre));
    strncpy(P->entrada, input_, 100);
    strncpy(P->salida, output_, 100);
    P->anio = year_;
    P->precio_minimo = minimun_price_;
    P->mostrar = show_;
    P->n_anios = 0;
    return P;
}
/*
    * Esta función obtiene los años de un archivo
    * Entrada: Recibe un padre (el cual contiene el archivo a abrir)
    * Salida: Retorna un arreglo de enteros con los años
*/
int* obtenerAnios(Padre *P){
    FILE *fp;
    fp = fopen(P->entrada, "r");
    int *anios = (int*)calloc(100, sizeof(int)), i = 0, anio;
    char linea[256];
    while(fgets(linea, 256, fp)){
        int largo = strlen(linea);
        int anio = obtenerAnio(linea, largo - 1);
        float precio_juego = obtenerPrecio(linea, largo);
        if(buscarAnio(anio, anios) == -1 
            && anio >= P->anio 
            && precio_juego >= P->precio_minimo){
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
    P->n_anios = i;
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
        printf("El elemento es %c\n", linea[pos + j]);
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
    * Esta función ordena el archivo de entrada 
    * del padre y escribe en el archivo de salida
    * Entrada: Recibe un padre
    * Salida: No retorna nada
*/
void archivoOrdenado(Padre *P, int *anios){
    FILE *archivoIntermedio = fopen("intermedio.txt", "a"); 
    for(int i=0; i < P->n_anios; i++){
        escribirArchivo(P->entrada, anios[i], P->precio_minimo, archivoIntermedio);
    }
    fclose(archivoIntermedio);
}
/*
    * Esta función escribe en el archivo entregado
    * Entrada: Recibe el nombre del archivo de entrada,
    * el año a filtrar, el precio mínimo a filtrar y el archivo a escribir
    * Salida: No retorna nada
*/
void escribirArchivo(char entrada[], int anio, float precio_min, FILE *archivo){
    FILE *archivoE = fopen(entrada, "r");
    char linea[256];
    int i = 0;
    while(fgets(linea, 256, archivoE)){
        int largo = strlen(linea);
        int anio_ = obtenerAnio(linea, largo - 1);
        float precio_juego = obtenerPrecio(linea, largo);
        if(anio_ == anio && (precio_juego >= precio_min || precio_juego  == 0.0)){
            fputs(linea, archivo);
        }
        memset(linea, 0, 256);
    }
    fclose(archivoE);
}
/*
    * Esta función muestra el archivo de salida
    * Entrada: Recibe un arreglo de caracteres con el nombre del archivo
    * a imprimir
    * Salida: No retorna nada.
*/
void printArchivo(char archivo[]){
    FILE *fp = fopen(archivo, "r");
    char linea[256];
    while(fgets(linea, 256, fp)){
        printf("%s", linea);
        memset(linea, 0, 256);
    }
    fclose(fp);
}
/*
    * Función que retorna un arreglo de enteros con las posiciones
    * iniciales y finales del achivo ydonde empieza cada año en el archivo.
    * Entrada: Recibe un padre
    * Salida: Retorna un arreglo de enteros con las posiciones
*/
int *posicionesArchivo(Padre *P){
    int *posiciones = (int*)malloc(100 * sizeof(int));
    FILE *fp = fopen("intermedio.txt", "r");
    char linea[256];
    int i = 1, anio_ = P->anio;
    posiciones[0] = 0;
    while(fgets(linea, 256, fp)){
        int largo = strlen(linea);
        int anio = obtenerAnio(linea, largo);
        if(anio != anio_){
            posiciones[i] = ftell(fp) - largo;
            i++;
            anio_ = anio;
        }
        memset(linea, 0, 256);
    }
    posiciones[i] = ftell(fp);
    i++;
    P->n_pos = i;
    fclose(fp);
    return posiciones;
}
/*
    * Función que calcula los datos de los juegos recibidos y los escribe
    * en el archivo de salida.
    * Entrada: Recibe el padre.
    * Salida: No retorna nada.
*/

void Ejecutar(Padre *P){
    int *anios = obtenerAnios(P);
    archivoOrdenado(P, anios);
    int *posiciones = posicionesArchivo(P);
    char str2[10];
    for(int i=0; i < P->n_pos - 1; i++){
        escribirAnios(P, anios[i]);
        int pid = fork();
        if(pid == 0){
            Hijo *H = crearHijo("intermedio.txt", P->salida, posiciones[i], posiciones[i + 1]);
            calcularDatosAnio(H);
            nombreJprecio(H);
            imprimirDatos(H);
            return;
        }
        else{
            wait(NULL);
        }
    }
    if(P->mostrar == 1){
        printArchivo(P->salida);
    }
}
/*
    * Función que escribe el año en el archivo de salida
    * Entrada: Recibe el padre y el año a escribir
    * Salida: No retorna nada
*/
void escribirAnios(Padre *P, int anio){
    FILE *fp = fopen(P->salida, "a");
    char str[10];
    if(ftell(fp) != 0){
        fputs("\n", fp);
    }
    sprintf(str, "%d", anio);
    fputs("Año: ", fp);
    fputs(str, fp);
    fputs("\n", fp);
    fclose(fp);
}