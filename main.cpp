#include <iostream>
#include "Fabryka.h"
#include "ListaDwukierunkowa.h"
#include "Iterator.h"

using namespace std;

/// <summary>
/// Funkcja główna programu testującego działanie dwukierunkowej listy oraz iteratora.
/// </summary>
/// <returns>Zwraca 0 po poprawnym zakończeniu programu.</returns>

int main() {
    FabrykaWezlow fabryka;
    ListaDwukierunkowa lista(&fabryka);

    cout << "=== TEST DODAWANIA ===" << endl;
    lista.dodajNaPoczatek(10); // [10]
    lista.dodajNaPoczatek(5);  // [5, 10]
    lista.dodajNaKoniec(30);   // [5, 10, 30]
    lista.dodajPodIndeks(2, 20); // [5, 10, 20, 30]
    lista.wyswietl();

    cout << "\n=== TEST WYSWIETLANIA W ODWROTNEJ KOLEJNOSCI ===" << endl;
    lista.wyswietlOdTylu(); // Oczekiwane: 30 20 10 5

    cout << "\n=== TEST ITERATORA (Nastepny / Poprzedni element) ===" << endl;
    Iterator it = lista.utworzIterator();
    if (!it.czyKoniec()) {
        cout << "Aktualny (poczatek): " << it.pobierzWartosc() << endl;

        it.nastepny(); // Przejście do następnego
        cout << "Nastepny element: " << it.pobierzWartosc() << endl;

        it.nastepny(); // Przejście kolejny raz w przód
        cout << "Kolejny nastepny element: " << it.pobierzWartosc() << endl;

        it.poprzedni(); // Powrót do poprzedniego
        cout << "Po cofnieciu (poprzedni element): " << it.pobierzWartosc() << endl;
    }

    cout << "\n=== TEST USUWANIA ===" << endl;
    lista.usunZPoczatek(); // Usuwa 5 -> [10, 20, 30]
    cout << "Po usunieciu z poczatku: ";
    lista.wyswietl();

    lista.usunZKoniec(); // Usuwa 30 -> [10, 20]
    cout << "Po usunieciu z konca: ";
    lista.wyswietl();

    lista.dodajNaKoniec(40); // [10, 20, 40]
    lista.dodajNaKoniec(50); // [10, 20, 40, 50]
    cout << "Po dodaniu elementow: ";
    lista.wyswietl();

    lista.usunPodIndeks(1); // Usuwa element spod indeksu 1 (czyli wartość 20) -> [10, 40, 50]
    cout << "Po usunieciu spod indeksu 1: ";
    lista.wyswietl();

    cout << "\n=== TEST CZYSZCZENIA LISTY ===" << endl;
    lista.wyczysc();
    cout << "Rozmiar listy po wyczyszczeniu: " << lista.pobierzRozmiar() << endl;
    lista.wyswietl();

    return 0;
}
//Nowa metoda