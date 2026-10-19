#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include "Wezel.h"
#include "Fabryka.h"

class ListaDwukierunkowa {
private:
    Wezel* poczatek;
    Wezel* koniec;
    int rozmiar;
    Fabryka* fabryka;

public:
    ListaDwukierunkowa(Fabryka* fabryka);
    ~ListaDwukierunkowa();

    void dodajNaPoczatek(int wartosc);
    void dodajNaKoniec(int wartosc);
    void dodajPodIndeks(int indeks, int wartosc);

    int pobierzRozmiar() const;
    void wyswietl() const; // Dodatkowa metoda pomagająca zweryfikować stan listy
};

#endif