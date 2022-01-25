#include "Funciones.cpp"

int main() {
    int seguir = 0;
    Funciones f;
    system("title � Calculadora 2.0 �");
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