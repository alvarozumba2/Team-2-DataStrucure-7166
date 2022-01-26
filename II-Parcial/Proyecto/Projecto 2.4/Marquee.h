/**
 * @file Marquee.h
 * @author Gustavo Aguas, Cristian Felix, Carlos Ipiales, Alvaro Zumba
 * @brief Marquee.h
 * @version 2.4
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <string.h>
#include <windows.h>
#include <thread>
#include <conio.h>
using namespace std;

/**
 * @brief class Marquee
 * 
 */
class Marquee
{
public:
    /**
     * @brief Construct a new Marquee object
     *
     */
    Marquee(string);

    /**
     * @brief Ocultar cursor
     *
     */
    void cursorHide();

    /**
     * @brief Imprime en coordenadas
     *
     * @param x
     * @param y
     * @param format
     * @param ...
     */
    void coordenadas(int x, int y, string format, ...);

    /**
     * @brief Get the Console Cursor Position object
     *
     * @param hConsoleOutput
     * @return COORD
     */
    COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);

    /**
     * @brief Impresion de marquesina
     *
     */
    void marquee();

    /**
     * @brief ajusta marquesina en consola
     *
     */
    void trans();

private:
    string marquesina;
    int index = 0;
};

/**
 * @brief Construct a new Marquee:: Marquee object
 * 
 * @param marquee 
 */
Marquee::Marquee(string marquee)
{
    this->marquesina = marquee;
}

/**
 * @brief cursorHide
 * 
 */
void Marquee::cursorHide()
{
    HANDLE hwnd;
    hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;

    info.bVisible = 0;
    info.dwSize = 1;

    SetConsoleCursorInfo(hwnd, &info);
}

/**
 * @brief coordenadas
 * 
 * @param x 
 * @param y 
 * @param format 
 * @param ... 
 */
void Marquee::coordenadas(int x, int y, string format, ...)
{
    const char *c = format.c_str();
    va_list args;
    va_start(args, format);
    printf("\033[%d;%dH", x, y);
    vprintf(c, args);
    va_end(args);
    fflush(stdout);
}

/**
 * @brief GetConsoleCursorPosition
 * 
 * @param hConsoleOutput 
 * @return COORD 
 */
COORD Marquee::GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        COORD invalid = {10, 10};
        return invalid;
    }
}

/**
 * @brief marquee
 * 
 */
void Marquee::marquee()
{
    string logo = marquesina;
    int velocidad = 900;
    Sleep(600);
    cursorHide();
    int stringSize = logo.length();
    string msg;
    bool ciclo = true;
    for (index; ciclo == true; index++)
    {
        msg = "\t\t\t\t" + logo.substr(index % stringSize) + logo.substr(0, index % stringSize);
        coordenadas(0, 0, msg);
        Sleep(velocidad);
        if (GetAsyncKeyState(VK_RETURN))
        {
            ciclo = false;
            break;
        }
    }
}

/**
 * @brief trans
 * 
 */
void Marquee::trans()
{
    COORD cord;
    cord = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
    std::thread t1(&Marquee::marquee, this);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
    system("pause");
    t1.join();
    cord.Y++;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}