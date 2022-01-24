#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000
#define F1 59
#define ESC 27
#define Enter 13
#define Atras 8
#define BIP 7

#include <conio.h>
#ifndef	_CONIO_H_
#define getch() getchar()
#endif

#ifdef __linux__
#define CLEAN "CLEAR"
#endif

#ifdef __WIN32__
#define CLEAN "CLS"
#endif

/** \brief Program menu
 *
 * \return int: Ascii value of 1, 2, H, h, F1 or ESC
 */
int menu();

/** \brief Requests a combined operation from the user
 *
 * \return int: Ascii value of ESC or BackSpace
 */
int operacionCombinada();

/** \brief Check if the string entered has syntax or semantic mathematical errors
 *
 * \param char*: String pointer
 * \param If have errors, it show in screen
 * \return int: A negative number if there is any error, 0 if the string has nothing and 1 if it is OK
 */
int validar(char*);

/** \brief Sets the numbers of a string according to its sign and if it is decimal or integer
 *
 * \param char*: String pointer
 * \param int: Length of the selected string
 * \return double*: Pointer to array, the first number indicates the quantity of numbers that follow
 */
double *numbersSetter(char*,int);

/** \brief Insert a number in the string
 *
 * \param char*: Initial pointer of the string
 * \param int: Length of the selected string
 * \param double: Number to insert
 * \param char*: Pointer to the rest of the string
 * \return void
 */
void insertNumberInString(char*,int,double,char*);

/** \brief Solve the parentheses of a string
 *
 * \param char*: String pointer
 * \return int: 1 if there is parentheses, -1 if not
 */
int parentesis(char*);

/** \brief Separates and resolves terms of a string
 *
 * \param char*: String pointer
 * \return int: 1 if can separate in terms, 0 if not
 */
int terminos(char*);

/** \brief Add the numbers of a string
 *
 * \param char*: String pointer
 * \param int: Length of the selected string
 * \return double: The result
 */
double calculoSimple(char*,int);

/** \brief Performs operations of multiplication, division and exponentiation with the numbers of a string
 *
 * \param char*: String pointer
 * \param int: Length of the selected string
 * \return double: The result
 */
double calculoTermino(char*,int);

/** \brief Calculate a exponentiation
 *
 * \param double: The base
 * \param double: The exponent
 * \return double: The result
 */
double potencia(double,double);

char* getString(int,char*);

//int isFloat(float);

#endif // FUNCIONES_H_INCLUDED
