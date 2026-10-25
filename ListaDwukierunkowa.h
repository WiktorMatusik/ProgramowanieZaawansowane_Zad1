#ifndef LISTA_DWUKIERUNKOWA_H
#define LISTA_DWUKIERUNKOWA_H

#include "Wezel.h"
#include "fabryka.h"
#include "Iterator.h"

/// <summary>
/// Klasa implementująca dwukierunkową listę liczb całkowitych z obsługą dodawania, usuwania i wyświetlania elementów.
/// </summary>

class ListaDwukierunkowa {
private:
    Wezel* poczatek;
    Wezel* koniec;
    int rozmiar;
    FabrykaWezlow* fabryka;

public:
    ListaDwukierunkowa(FabrykaWezlow* fabryka);
    ~ListaDwukierunkowa();


    void dodajNaPoczatek(int wartosc);
    void dodajNaKoniec(int wartosc);
    void dodajPodIndeks(int indeks, int wartosc);


    void usunZPoczatek();
    void usunZKoniec();
    void usunPodIndeks(int indeks);


    void wyczysc();

    void wyswietl() const;
    void wyswietlOdTylu() const;


    Iterator utworzIterator() const;

    int pobierzRozmiar() const;
};

#endif