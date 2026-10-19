#ifndef WEZEL_H
#define WEZEL_H

class Wezel {
public:
    int wartosc;
    Wezel* nastepny;
    Wezel* poprzedni;

    Wezel(int val, Wezel* pop = nullptr, Wezel* nast = nullptr);
};

#endif