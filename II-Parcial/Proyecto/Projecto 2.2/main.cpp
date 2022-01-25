#include <iostream>
#include <thread>
#include <Windows.h>

#include "Marquee.h"
#include "Funciones.cpp"

void marquee_limit(std::string text, size_t limite) {
    bool ciclo = true;
    while (ciclo)
    {
        std::string temp = text;
        text.erase(0, 1);
        text += temp[0];
        std::this_thread::sleep_for(std::chrono::milliseconds(950));
        //poner titulo en la consola

        SetConsoleTitleA(text.substr(0, limite).c_str());
        if (GetAsyncKeyState(VK_RETURN)) {
            ciclo = false;
            break;
        }

    }
}

int main() {

    int seguir = 0;
    Funciones f;
    cout << " " << endl;
    std::string test = "  ESTRUCTURA  DE  DATOS  7166  ";
    std::thread t2(marquee_limit, test, test.size());
    Marquee mark1("  AGUAS  FELIX  IPIALES  ZUMBA  ");
    cout << " " << endl;
    mark1.trans();
    cout << "/////////////// Calculadora de expresiones aritmeticas ///////" << endl;
    while (seguir != ESC) {
        switch (f.menu()) {
        case '1':
            seguir=f.operacionCombinada();
            break;
        case '2':
            //seguir=ecuacion();
            break;
        case F1: case 'h': case 'H':
            system("cls");
            cout << "________________________________________________________________________________" << endl;
            cout << "  Este progama resuelve cualquier operacion matematica que el usuario desee.\n" << endl;
            cout << "  Caracteres validos ()*+,-./0123456789^\n\n" << endl;
            cout << "  Use ESC para salir y Retroceso o 'b' para volver al menu anterior" << endl;
            cout << "________________________________________________________________________________" << endl;
            do {
                //setbuf(stdin, NULL);
                seguir = _getch();
            } while (seguir != ESC && seguir != Atras && seguir != 'B' && seguir != 'b');
            break;
        case ESC:
            seguir = ESC;
        }
    }return 0;
}
