#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <windows.h> // libreria para modificar la pantalla

#define TAM 1000
#define F1 59
#define ESC 27
#define Enter 13
#define Atras 8
#define BIP 7

using namespace std;

class Funciones
{
private:
public:
    int menu();
    int operacionCombinada();
    char *getString(int, char *);
    int validar(char *);
    int parentesis(char *);
    int terminos(char *);
    double calculoSimple(char *, int);
    void insertNumberInString(char *, int, double, char *);
    double calculoTermino(char *, int);
    double *numbersSetter(char *, int);
    double potencia(double, double);
};

#endif // FUNCIONES_H
