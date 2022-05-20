#include <iostream>

void losuj(int* tablica, int rozmiar) {
    int i;
    for (i = 0; i < rozmiar; ++i) {
        tablica[i] = rand() % 30;
    }
}
void wypisz(int* tablica, int rozmiar) {
    int i;
    for (i = 0; i < rozmiar; ++i) {
        printf("%d ", tablica[i]);
    }
    printf("\n");
}

//O(n)
int wyszukajLiniowo(int* tablica, int rozmiar, int poszukiwanaLiczba) {
    //np. -1 gdy elementu nie ma
    //indeks tablicy
    int indeks = -1, iterator;
    for (iterator = 0; iterator < rozmiar; ++iterator) {
        if (tablica[iterator] == poszukiwanaLiczba) {
            indeks = iterator;
            break;
        }
    }
    return indeks;
}

int wyszukajBinarnie(int lewy, int prawy, int* tablica, int liczbaSzukana) {
    if (lewy > prawy) {
        return -1;
    }
    int srodekIdx = (lewy + prawy) / 2;

    if (liczbaSzukana == tablica[srodekIdx]) {
        return srodekIdx;
    }

    if (liczbaSzukana < tablica[srodekIdx]) {
        return wyszukajBinarnie(lewy, srodekIdx - 1, tablica, liczbaSzukana);
    }
    else {
        return wyszukajBinarnie(srodekIdx + 1, prawy , tablica, liczbaSzukana);
    }
}

void sortuj(int* tablica, int rozmiar) {
    int i, j, tmp;
    for (j = 0; j < rozmiar - 1; j++)
        for (i = 0; i < rozmiar - 1; i++)
            if (tablica[i] > tablica[i + 1]) {
                tmp = tablica[i];
                tablica[i] = tablica[i + 1];
                tablica[i + 1] = tmp;
            }
}

#define N 10

struct ListaJednoKierunkowa {
    struct ListaJednoKierunkowa* prawy;
    int wartosc;
};

//Zdejmowanie ze stosu
int pop(struct ListaJednoKierunkowa** lista) {
    int wartoscDoZwrocenia = -1;
    if (*lista == 0) {
        printf("Stos jest pusty\n");
    }
    else {
        wartoscDoZwrocenia = (*lista)->wartosc;
        struct ListaJednoKierunkowa* nastepny = (* lista)->prawy;
        free(*lista);
        *lista = nastepny;
    }

    return wartoscDoZwrocenia;
}

//Wstawianie do stosu
void push(struct ListaJednoKierunkowa** lista, int wartosc) {
    struct ListaJednoKierunkowa* nowaLista = 
                (struct ListaJednoKierunkowa*)malloc(sizeof(struct ListaJednoKierunkowa));
    nowaLista->prawy = 0;
    nowaLista->wartosc = wartosc;

    if (*lista == 0) {
        *lista = nowaLista;
    }
    else {
        nowaLista->prawy = *lista;
        *lista = nowaLista;
    }
}

void showStack(struct ListaJednoKierunkowa *head) {
    ListaJednoKierunkowa *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->wartosc);
        temp = temp->prawy;
    }
}

int main()
{
    int tablica[N];
    losuj(tablica, N);
    sortuj(tablica, N);
    wypisz(tablica, N);

    int indeks = wyszukajBinarnie(0, N-1, tablica, 18);
    printf("indeks: %d = %d", indeks, tablica[indeks]);

    struct ListaJednoKierunkowa * stos = 0;
    push(&stos, 10);
    push(&stos, 20);
    push(&stos, 30);
    printf("\n");
    showStack(stos);

    return 0;
}
