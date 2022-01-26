/**
 * @file Funciones.cpp
 * @author Gustavo Aguas, Cristian Felix, Carlos Ipiales, Alvaro Zumba
 * @brief Funciones.cpp
 * @version 2.4
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Funciones.h"
/**
 * @brief menu
 *
 * @return int
 */
int Funciones::menu()
{
    int seguir = 0;
    system("cls");
    cout << "|--------------------------------------------------------------------------------|" << endl;
    cout << "|                       Bienvenido a Calculaneitor 2000                          |" << endl;
    cout << "| Que deseas Hacer?                                                              |" << endl;
    cout << "|--------------------------------------------------------------------------------|" << endl;
    cout << "|  1 - Comprobar una operacion aritmetica                                        |" << endl;
    cout << "|  2 - Pixelar una Imagen                                                        |" << endl;
    cout << "|  3 - Obtener informacion del Programa                                          |" << endl;
    cout << "|--------------------------------------------------------------------------------|\n\n"
         << endl;
    do
    {
        // setbuf(stdin, NULL);
        seguir = _getch();
    } while (seguir != ESC && !(seguir > '0' && seguir < '4'));
    return seguir;
}

/**
 * @brief operacionCombinada
 *
 * @return int
 */

int Funciones::operacionCombinada()
{
    int continuar;
    do
    {
        char pString[TAM];
        string inString;
        // char* pString;
        // char input[TAM];
        double output;
        // pString = &input;
        system("cls");
        cout << "|--------------------------------------------------------------------------------|" << endl;
        cout << "|Ingrese la expresion aritmetica que desea comprobar o realizar:                 |" << endl;
        cout << "|--------------------------------------------------------------------------------|\n"
             << endl;
        // cin >> pString;
        // strcpy_s(pString, inString);
        // gets_s(pString);
        getString(TAM, pString);
        cout << "|--------------------------------------------------------------------------------|" << endl;
        if (validar(pString) < 0)
        {
            // printf("%c", BIP);
            Beep(523, 500);
        }
        else if (validar(pString) > 0)
        {
            system("cls");
            cout << "|--------------------------------------------------------------------------------|" << endl;
            int largo;
            printf(" %s", pString);
            while (strchr(pString, '(') != NULL)
            {
                parentesis(pString);
                printf("\n\n %s", pString);
            }
            while (strchr(pString, '*') != NULL || strchr(pString, '/') != NULL || strchr(pString, '^') != NULL)
            {
                terminos(pString);
                printf("\n\n %s", pString);
            }
            largo = strlen(pString);
            output = calculoSimple(pString, largo);
            printf("=%0.2f\n\n", output);
        }
        else
        {
            printf("\n\t          \\(o_o')/ no hay nada que resolver o analizar\n\n", 168);
        }
        printf("|--------------------------------------------------------------------------------|\n");
        printf("|           Pulse la tecla espacio para ingresar una expresion nuevamente        |\n");
        printf("|           o presione delete(<-) para regresar al menu principal       |\n");
        printf("|--------------------------------------------------------------------------------|\n");
        do
        {
            continuar = 0;
            continuar = _getch();
        } while (continuar != ' ' && continuar != ESC && continuar != Atras && continuar != 'B' && continuar != 'b');
    } while (continuar != ESC && continuar != Atras && continuar != 'B' && continuar != 'b');
    return continuar;
}

/**
 * @brief getString
 *
 * @param large
 * @param aux
 * @return char*
 */
char *Funciones::getString(int large, char *aux)
{
    fgets(aux, large, stdin);
    if (aux[strlen(aux) - 1] == '\n')
    {
        aux[strlen(aux) - 1] = '\0';
    }
    return aux;
}

/**
 * @brief validar
 *
 * @param puntero
 * @return int
 */
int Funciones::validar(char *puntero)
{
    int index, flag = 1, flagErrorParentesis = 0, errorSintax = 0, errorParentesis = 0, nada = 1;
    char *pAux;
    for (int i = 0; i < TAM; i++)
    {
        pAux = puntero + i;
        index = *pAux;
        if (index == '\0')
        {
            break;
        }
        nada = 0;
        if (index == '(')
        { // Verifica los parentesis
            errorParentesis++;
        }
        if (index == ')')
        {
            if (errorParentesis <= 0)
            {
                flagErrorParentesis = 1;
            }
            errorParentesis--;
        }
        if (index == '*' || index == '/')
        { // Errores de sintaxis
            errorSintax++;
            if (errorSintax > 1)
            {
                if (flag != -3)
                {
                    printf("\n Error de sintaxsis: \"%c%c\"", *(pAux - 1), index);
                    flag = -3;
                }
                else
                {
                    printf(", \"%c%c\"", *(pAux - 1), index);
                }
            }
        }
        else
        {
            errorSintax = 0;
        }

        if (!(index >= '(' && index <= '9') && index != '^')
        { // todo lo q no sea ()*+,-./0123456789^
            if (index == ' ')
            {
                nada = 1;
                continue;
            }
            if (flag != -1)
            {
                printf("\n Error, caracteres invalidos: %c", index);
                flag = -1;
            }
            else
            {
                printf(", %c", index);
            }
        }
    }
    if (errorParentesis != 0 || flagErrorParentesis)
    {
        printf("\n Error, faltan o sobran parentesis");
        flag = -2;
    }
    if (flag < 0)
    {
        printf("\n");
    }
    if (nada && flag)
    {
        flag = 0;
    }
    return flag;
}

/**
 * @brief parentesis
 *
 * @param puntero
 * @return int
 */
int Funciones::parentesis(char *puntero)
{
    short index, flag, flagTermino;
    int largoInicio, largoParentesis;
    char *pAux, *pInicio, *pFin;
    double output;
    do
    {
        largoInicio = 0;
        largoParentesis = 0;
        flagTermino = 0;
        flag = -1;
        for (int i = 0; i < TAM; i++)
        {
            pAux = puntero + i;
            index = *pAux;
            if (!flag)
            {
                largoInicio++;
            }
            if (index == ')')
            {
                flag = 0;
                largoParentesis++;
                pFin = pAux + 1;
                break;
            }
            if (flag)
            {
                largoParentesis++;
                if (index == '*' || index == '/' || index == '^')
                {
                    flagTermino = 1;
                }
            }
            if (index == '(')
            {
                pInicio = pAux;
                if (flag)
                {
                    largoInicio = largoInicio + largoParentesis - 1;
                    largoParentesis = 0;
                    flagTermino = 0;
                }
                largoParentesis++;
                flag = 1;
            }
        }
        if (flagTermino == 1 && flag != -1)
        {
            terminos(pInicio + 1);
            printf("\n\n %s", puntero);
        }
    } while (flagTermino != 0);
    if (flag != -1)
    {
        output = calculoSimple(pInicio, largoParentesis);
        insertNumberInString(puntero, largoInicio, output, pFin);
    }
    return flag;
}

/**
 * @brief terminos
 *
 * @param puntero
 * @return int
 */
int Funciones::terminos(char *puntero)
{
    int index, flag = 0;
    int largoInicio = 0, largoTermino = 0;
    char *pAux, *pInicio = puntero, *pFin;
    float output;
    for (int i = 0; i < TAM; i++)
    {
        pAux = puntero + i;
        index = *pAux;
        largoTermino++;
        if (index == '+' || index == '-')
        {
            if (largoTermino > 0 && flag)
            {
                if (!(*(pAux - 1) == '*' || *(pAux - 1) == '/' || *(pAux - 1) == '^'))
                {
                    pFin = pAux;
                    break;
                }
            }
            if (largoTermino > 0 && !flag)
            {
                largoInicio = largoInicio + largoTermino;
                largoTermino = 0;
                pInicio = pAux + 1;
            }
        }
        if (index == '*' || index == '/' || index == '^')
        {
            if (flag)
            {
                pFin = pAux;
                break;
            }
            flag = 1;
        }
        if (index == '\0' || index == ')' || index == ')')
        {
            pFin = pAux;
            break;
        }
    }
    if (flag != 0)
    {
        output = calculoTermino(pInicio, largoTermino);
        insertNumberInString(puntero, largoInicio, output, pFin);
    }
    return flag;
}

/**
 * @brief calculoSimple
 *
 * @param puntero
 * @param largo
 * @return double
 */
double Funciones::calculoSimple(char *puntero, int largo)
{
    double *pNumeros;
    pNumeros = numbersSetter(puntero, largo);
    // printf("\nCantidad de numeros: %.0f",*(pNumeros+0));
    double output = 0;
    for (int i = 1; i <= *(pNumeros + 0); i++)
    {
        // printf("\n Numero %d: %.2f",i,*(pNumeros+i));
        output = output + *(pNumeros + i);
    }
    return output;
}

/**
 * @brief insertNumberInString
 *
 * @param puntero
 * @param largoInicio
 * @param number
 * @param pFin
 */
void Funciones::insertNumberInString(char *puntero, int largoInicio, double number, char *pFin)
{
    char auxNumber[50] = {""};
    char auxString[TAM] = {""};
    strncpy_s(auxString, puntero, largoInicio); // printf("\nstring%s\n",auxString);
    sprintf_s(auxNumber, "%.2f", number);
    strcat_s(auxString, auxNumber); // printf("\nstring%s\n",auxString);
    strcat_s(auxString, pFin);      // printf("\nstring%s\n",auxString);
    strcpy(puntero, auxString);
}

/**
 * @brief calculoTermino
 *
 * @param puntero
 * @param largo
 * @return double
 */
double Funciones::calculoTermino(char *puntero, int largo)
{
    double *pNumeros;
    pNumeros = numbersSetter(puntero, largo);
    // printf("\nCantidad de numeros: %.0f",*(pNumeros+0));
    double output, numAux;
    int index, operador;
    char *pAux = puntero;
    // printf("\n Numero %d: %.2f",1,*(pNumeros+1));
    output = *(pNumeros + 1);
    for (int i = 2; i <= *(pNumeros + 0); i++)
    {
        for (int j = 0; j < largo; j++)
        {
            index = *(pAux + j);
            if (index == '*' || index == '/' || index == '^')
            {
                operador = index;
                pAux = pAux + j + 1;
                break;
            }
        }
        // printf("\n Numero %d: %.2f",i,*(pNumeros+i));
        numAux = *(pNumeros + i);
        if (operador == '*')
        {
            // printf("\n %.0f*%.0f",output,numAux);
            output = output * numAux;
        }
        if (operador == '/')
        {
            // printf("\n %.0f/%.0f",output,numAux);
            output = output / numAux;
        }
        if (operador == '^')
        {
            // printf("\n %.0f^%.0f",output,numAux);
            output = potencia(output, numAux);
        }
        // printf("=%.0f\n",output);
    }
    return output;
}

/**
 * @brief numbersSetter
 *
 * @param puntero
 * @param largo
 * @return double*
 */
double *Funciones::numbersSetter(char *puntero, int largo)
{
    int negativeFlag = 0, numFlag = 0, floatFlag = 0;
    int numCounter = 1, floatConter = 0;
    double aux;
    static double auxNums[50];
    for (int i = 0; i < 50; i++)
    {
        auxNums[i] = 0;
    }
    for (int i = 0; i < largo + 1; i++)
    {
        aux = *(puntero + i) - 48;
        if (*(puntero + i) == '-')
        { // marca negativos
            if (negativeFlag && numFlag)
            {
                auxNums[numCounter] = 0 - auxNums[numCounter];
                numCounter++;
                numFlag = 0;
                floatFlag = 0;
            }
            else if (!negativeFlag && numFlag)
            {
                numCounter++;
                negativeFlag = 1;
                numFlag = 0;
                floatFlag = 0;
            }
            else if (!negativeFlag && !numFlag)
            {
                negativeFlag = 1;
            }
            else
            {
                negativeFlag = 0;
            }
        }
        else
        {
            if (aux >= 0 && aux <= 9)
            { // toma numeros
                if (floatFlag)
                {
                    auxNums[numCounter] = auxNums[numCounter] + aux / potencia(10, floatConter);
                    floatConter++;
                }
                else
                {
                    auxNums[numCounter] = auxNums[numCounter] * 10 + aux;
                }
                numFlag = 1;
            }
            else if (*(puntero + i) == '.' || *(puntero + i) == ',')
            { // marca decimales
                floatFlag = 1;
                floatConter = 1;
            }
            else
            { // setea negativos y numeros
                if (negativeFlag && numFlag)
                {
                    auxNums[numCounter] = 0 - auxNums[numCounter];
                    negativeFlag = 0;
                }
                if (numFlag)
                {
                    numCounter++;
                    numFlag = 0;
                    floatFlag = 0;
                }
            }
        }
    }
    auxNums[0] = numCounter - 1;
    /*for(int i=0;i<50;i++){
        if(auxNums[i]!=0){printf("%f",auxNums[i]);}
    }system("pause");*/
    return auxNums;
}

/**
 * @brief potencia
 *
 * @param numero
 * @param potencia
 * @return double
 */
double Funciones::potencia(double numero, double potencia)
{
    double resultado = 1, aux;
    int potenciaInt = potencia;
    if (potencia > 0)
    {
        for (int i = 0; i < potencia; i++)
        {
            resultado = resultado * numero;
            if (i == potenciaInt && potenciaInt != potencia)
            {
                aux = potencia - potenciaInt;
                printf("%f", aux);
                system("pause");
                resultado = resultado * (numero * aux);
            }
        }
    }
    else if (potencia < 0)
    {
        for (int i = 0; i < potencia; i++)
        {
            if (i != potenciaInt)
            {
                resultado = resultado / numero;
            }
            else if (potenciaInt != potencia)
            {
                aux = potencia - potenciaInt;
                resultado = resultado / (numero * aux);
            }
        }
    }
    return resultado;
}