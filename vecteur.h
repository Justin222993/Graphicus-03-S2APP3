#ifndef VECTEUR_H
#define VECTEUR_H

#include <iostream>
#include <stdexcept>
#include <type_traits>

using namespace std;

template<class T>
class Vecteur {
public:
    Vecteur();
    ~Vecteur();

    Vecteur(const Vecteur& copie);
    Vecteur& operator=(const Vecteur& copie);

    int getCapacite() const { return capacite; }
    int getTaille() const { return taille; }
    int getItemCourant() const { return itemCourant; }
    bool isVide() const { return taille == 0; }
    void vider();

    bool ajouter(const T& valeur);
    T retirer(int index);
    T& get(int index);
    const T& get(int index) const;

    T& operator[](int index);
    const T& operator[](int index) const;
    Vecteur<T>& operator+=(const T& valeur);
    Vecteur<T>& operator++();
    Vecteur<T>& operator--();

    template<typename U>
    friend ostream& operator<<(ostream& os, const Vecteur<U>& v);

    template<typename U>
    friend istream& operator>>(istream& is, Vecteur<U>& v);

private:
    T* liste;
    int capacite;
    int taille;
    int itemCourant;

    void doubleCapacite();
};

template<class T>
Vecteur<T>::Vecteur() : capacite(1), taille(0), itemCourant(0) {
    liste = new T[capacite];
}

template<class T>
Vecteur<T>::~Vecteur() {
    delete[] liste;
}

template<class T>
Vecteur<T>::Vecteur(const Vecteur& copie)
    : capacite(copie.capacite), taille(copie.taille), itemCourant(copie.itemCourant)
{
    liste = new T[capacite];
    for (int i = 0; i < taille; i++)
        liste[i] = copie.liste[i];
}

template<class T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur& copie) {
    if (this != &copie) {
        delete[] liste;
        capacite = copie.capacite;
        taille = copie.taille;
        itemCourant = copie.itemCourant;
        liste = new T[capacite];
        for (int i = 0; i < taille; i++)
            liste[i] = copie.liste[i];
    }
    return *this;
}

template<class T>
void Vecteur<T>::vider() {
    taille = 0;
    itemCourant = 0;
}

template<class T>
void Vecteur<T>::doubleCapacite() {
    capacite *= 2;
    T* nouvelle = new T[capacite];
    for (int i = 0; i < taille; i++)
        nouvelle[i] = liste[i];
    delete[] liste;
    liste = nouvelle;
}

template<class T>
bool Vecteur<T>::ajouter(const T& valeur) {
    if (taille >= capacite)
        doubleCapacite();
    liste[taille++] = valeur;
    return true;
}

template<class T>
T Vecteur<T>::retirer(int index) {
    if (index < 0 || index >= taille)
        throw out_of_range("Index invalide");

    T valeur = liste[index];

    for (int i = index; i < taille - 1; i++)
        liste[i] = liste[i + 1];

    --taille;

    if (itemCourant >= taille && taille > 0)
        itemCourant = taille - 1;

    return valeur;
}

template<class T>
T& Vecteur<T>::get(int index) {
    if (index < 0 || index >= taille)
        throw out_of_range("Index invalide");
    return liste[index];
}

template<class T>
const T& Vecteur<T>::get(int index) const {
    if (index < 0 || index >= taille)
        throw out_of_range("Index invalide");
    return liste[index];
}

template<class T>
T& Vecteur<T>::operator[](int index) { return get(index); }

template<class T>
const T& Vecteur<T>::operator[](int index) const { return get(index); }

template<class T>
Vecteur<T>& Vecteur<T>::operator+=(const T& valeur) {
    ajouter(valeur);
    return *this;
}

template<class T>
Vecteur<T>& Vecteur<T>::operator++() {
    if (itemCourant < taille - 1) itemCourant++;
    return *this;
}

template<class T>
Vecteur<T>& Vecteur<T>::operator--() {
    if (itemCourant > 0) itemCourant--;
    return *this;
}

template<typename U>
ostream& operator<<(ostream& os, const Vecteur<U>& v) {
    for (int i = 0; i < v.taille; i++) {
        if constexpr (is_pointer<U>::value) {
            if (v.liste[i]) os << *(v.liste[i]) << endl;
            else os << "NULL" << endl;
        }
        else {
            os << v.liste[i] << endl;
        }
    }
    return os;
}

template<typename U>
istream& operator>>(istream& is, Vecteur<U>& v) {
    U temp;
    while (is >> temp) {
        v.ajouter(temp);
    }
    return is;
}

#endif