#include "ListaDwukierunkowa.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ListaDwukierunkowa::ListaDwukierunkowa(FabrykaWezlow* fab)
    : poczatek(nullptr), koniec(nullptr), rozmiar(0), fabryka(fab) {}

ListaDwukierunkowa::~ListaDwukierunkowa() {
    wyczysc();
}

/// <summary>
/// Dodaje nowy element na początek listy dwukierunkowej.
/// </summary>
/// <param name="wartosc">Wartość do dodania na początek listy.</param>

void ListaDwukierunkowa::dodajNaPoczatek(int wartosc) {
    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, nullptr, poczatek);
    if (poczatek == nullptr) {
        koniec = nowyWezel;
    }
    else {
        poczatek->poprzedni = nowyWezel;
    }
    poczatek = nowyWezel;
    rozmiar++;
}

/// <summary>
/// Dodaje nowy element o podanej wartości na koniec listy dwukierunkowej.
/// </summary>
/// <param name="wartosc">Wartość, która zostanie dodana jako nowy element na końcu listy.</param>

void ListaDwukierunkowa::dodajNaKoniec(int wartosc) {
    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, koniec, nullptr);
    if (koniec == nullptr) {
        poczatek = nowyWezel;
    }
    else {
        koniec->nastepny = nowyWezel;
    }
    koniec = nowyWezel;
    rozmiar++;
}

/// <summary>
/// Dodaje nowy element o podanej wartości na określonym indeksie w liście dwukierunkowej.
/// </summary>
/// <param name="indeks">Pozycja, na której ma zostać dodany nowy element. Musi być w zakresie od 0 do rozmiar listy.</param>
/// <param name="wartosc">Wartość nowego elementu do dodania.</param>

void ListaDwukierunkowa::dodajPodIndeks(int indeks, int wartosc) {
    if (indeks < 0 || indeks > rozmiar) {
        throw out_of_range("Indeks poza zakresem listy!");
    }
    if (indeks == 0) {
        dodajNaPoczatek(wartosc);
        return;
    }
    if (indeks == rozmiar) {
        dodajNaKoniec(wartosc);
        return;
    }

    Wezel* temp = poczatek;
    for (int i = 0; i < indeks; ++i) {
        temp = temp->nastepny;
    }

    Wezel* nowyWezel = fabryka->utworzWezel(wartosc, temp->poprzedni, temp);
    temp->poprzedni->nastepny = nowyWezel;
    temp->poprzedni = nowyWezel;
    rozmiar++;
}

/// <summary>
/// Usuwa pierwszy element z listy dwukierunkowej.
/// </summary>

void ListaDwukierunkowa::usunZPoczatek() {
    if (poczatek == nullptr) {
        throw runtime_error("Lista jest pusta, nie ma czego usunąć!");
    }
    Wezel* temp = poczatek;      
    poczatek = poczatek->nastepny; 

    if (poczatek != nullptr) {
        poczatek->poprzedni = nullptr;
    }
    else {
        koniec = nullptr;
    }

    delete temp; 
    rozmiar--;
}

/// <summary>
/// Usuwa ostatni element z listy dwukierunkowej.
/// </summary>

void ListaDwukierunkowa::usunZKoniec() {
    if (koniec == nullptr) {
        throw runtime_error("Lista jest pusta, nie ma czego usunąć!");
    }
    Wezel* temp = koniec;        
    koniec = koniec->poprzedni;  

    if (koniec != nullptr) {
        koniec->nastepny = nullptr; 
    }
    else {
        poczatek = nullptr;
    }

    delete temp;
    rozmiar--;
}

/// <summary>
/// Usuwa element z listy dwukierunkowej na podanym indeksie.
/// </summary>
/// <param name="indeks">Indeks elementu do usunięcia (liczony od zera).</param>

void ListaDwukierunkowa::usunPodIndeks(int indeks) {
    if (indeks < 0 || indeks >= rozmiar) {
        throw out_of_range("Indeks poza zakresem listy!");
    }
    if (indeks == 0) {
        usunZPoczatek();
        return;
    }
    if (indeks == rozmiar - 1) {
        usunZKoniec();
        return;
    }

    Wezel* temp = poczatek;
    for (int i = 0; i < indeks; ++i) {
        temp = temp->nastepny; 
    }

    temp->poprzedni->nastepny = temp->nastepny;
    temp->nastepny->poprzedni = temp->poprzedni;

    delete temp; 
    rozmiar--;
}

/// <summary>
/// Usuwa wszystkie elementy z listy dwukierunkowej, zwalniając zaalokowaną pamięć.
/// </summary>

void ListaDwukierunkowa::wyczysc() {
    Wezel* temp = poczatek;
    while (temp != nullptr) {
        Wezel* nastepny = temp->nastepny;
        delete temp;
        temp = nastepny;
    }
    poczatek = nullptr;
    koniec = nullptr;
    rozmiar = 0;
}

/// <summary>
/// Wyświetla zawartość listy dwukierunkowej od początku do końca.
/// </summary>

void ListaDwukierunkowa::wyswietl() const {
    Wezel* temp = poczatek;
    cout << "Lista (od przodu): ";
    while (temp != nullptr) {
        cout << temp->wartosc << " ";
        temp = temp->nastepny;
    }
    cout << endl;
}

/// <summary>
/// Wyświetla zawartość listy dwukierunkowej od końca do początku.
/// </summary>

void ListaDwukierunkowa::wyswietlOdTylu() const {
    Wezel* temp = koniec;
    cout << "Lista (od tylu): ";
    while (temp != nullptr) {
        cout << temp->wartosc << " ";
        temp = temp->poprzedni;
    }
    cout << endl;
}

/// <summary>
/// Tworzy nowy iterator wskazujący na początek listy dwukierunkowej.
/// </summary>
/// <returns>Nowy obiekt Iterator ustawiony na pierwszy element listy.</returns>

Iterator ListaDwukierunkowa::utworzIterator() const {
    return Iterator(poczatek);
}

/// <summary>
/// Zwraca liczbę elementów w liście dwukierunkowej.
/// </summary>
/// <returns>Aktualny rozmiar (liczbę elementów) listy dwukierunkowej jako wartość typu int.</returns>

int ListaDwukierunkowa::pobierzRozmiar() const {
    return rozmiar;
}