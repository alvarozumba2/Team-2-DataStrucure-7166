/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Gustavo Aguas
*Cristian Felix
*Carlos Ipiales
*Alvaro Zumba
*TEMA: 
*FECHA DE CREACION : 15/01/2022
*FECHA DE ULTIMA MODIFICACION: 25/01/2022
* */


#include <iostream>
#include <thread>
#include <Windows.h>

#include "Marquee.h"
#include "Funciones.cpp"

/**
 * @brief marquee_limit
 * 
 * @param text 
 * @param limite 
 */
void marquee_limit(std::string text, size_t limite)
{
    bool ciclo = true;
    while (ciclo)
    {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(950));
        // poner titulo en la consola

        SetConsoleTitleA(text.substr(0, limite).c_str());
        if (GetAsyncKeyState(VK_RETURN))
        {
            ciclo = false;
            break;
        }
    }
}

/**
 * @brief main
 * 
 * @return int 
 */
int main()
{

    int seguir = 0;
    Funciones f;
    cout << " " << endl;
    std::string test = "  ESTRUCTURA  DE  DATOS  7166  ";
    std::thread t2(marquee_limit, test, test.size());
    Marquee mark1("  AGUAS  FELIX  IPIALES  ZUMBA  ");
    cout << " " << endl;
    mark1.trans();
    cout << "/////////////// Calculadora de expresiones aritmeticas ///////" << endl;
    while (seguir != ESC)
    {
        switch (f.menu())
        {
        case '1':
            seguir = f.operacionCombinada();
            break;
        case '2':
            // seguir=ecuacion();
            break;
        case '3':
            system("cls");
            cout << "|--------------------------------------------------------------------------------|" << endl;
            cout << "|                   UNIVERSIDAD DE LAS FUERZAS ARMADAS 'ESPE'                    |" << endl;
            cout << "|                            INGENIERIA EN SOFTWARE                              |" << endl;
            cout << "|                             ESTRUCTURA DE DATOS                                |" << endl;
            cout << "|                                                                                |" << endl;
            cout << "|  El programa esta disenado para resolver cualquiera operacion aritmetica que   |" << endl;
            cout << "|  el usuario desee, ademas de implementar una herramienta para pixelar imagenes |" << endl;
            cout << "|                                                                                |" << endl;
            cout << "|  Los operadores y caracteres que el programa acepta son:                       |" << endl;
            cout << "|  ()*+,-./0123456789^                                                           |" << endl;
            cout << "|                                                                                |" << endl;
            cout << "|  Para salir presione la tecla ESC                                              |" << endl;
            cout << "|  Para regresar al menu principal presione la tecla hacia atras o la letra b    |" << endl;
            cout << "|--------------------------------------------------------------------------------|" << endl;
            do
            {
                // setbuf(stdin, NULL);
                seguir = _getch();
            } while (seguir != ESC && seguir != Atras && seguir != 'B' && seguir != 'b');
            break;
        case ESC:
            seguir = ESC;
        }
    }
    return 0;
}