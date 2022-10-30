#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct freeGames{
    char *name;
    struct freeGames *next;
}FreeG;

typedef struct year{
    int year;
    float priceExpensive;
    float priceCheap;
    char *nameExpensive;
    char *nameCheap;
    float priceAcum;
    float nWindows;
    float nMacOs;
    float nLinuxs;
    int nGames;
    FreeG *freeGames;
}

typedef struct broker{

}Broker;