#include "zespolona.h"
#include <iostream>
zespolona::zespolona(){
    nazwa = "BRAK";
    rzecz = 0.0;
    urojo = 0.0;
}

zespolona::zespolona(std::string nazwa, float rzecz, float urojo){
    this -> nazwa = nazwa;
    this -> rzecz = rzecz;
    this -> urojo = urojo;
}

std::string zespolona::toString(){
    std::string wynik = nazwa + ": z = " + std::to_string(rzecz) + "+" + std::to_string(urojo) + "i";

    return wynik;
}

zespolona zespolona::operator + (const zespolona & argP){
    zespolona tmp(nazwa + "_" + argP.nazwa, rzecz + argP.rzecz, urojo + argP.urojo);
    return tmp;
}

zespolona & zespolona::operator++(){
    ++rzecz;
    return *this;
}

zespolona & zespolona::operator++(int){
    rzecz++;
    return *this;
}

bool zespolona::operator == (const zespolona &argP){
    return (rzecz==argP.rzecz && urojo == argP.urojo);
}

// operatory zdefiniowane poza klasa

zespolona operator + ( const float argL , const zespolona & argP){
    zespolona tmp(argP.nazwa + "_" = std::to_string(argL), argP.rzecz + argL, argP.urojo);
    return tmp;
}

std::ostream & operator << ( std::ostream &str, const zespolona & argP){

    str << argP.nazwa << ": z =" << std::to_string(argP.rzecz) << " + " + std::to_string(argP.urojo) << "i";
    return str;
}