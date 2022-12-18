#ifndef BUFFER_H
#define BUFFER_H
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>
#include <condition_variable>

const int TAM_BUF=10;   //tama o del buffer limitado
const int ESPERA=200;   //Espera en ms

using namespace std;

class Drone;
class BufferLimitado
{
    double *m_buf;         //puntero al inicio del buffer
    int m_tam;          //tama o del buffer
    int m_out;          //indice al siguiente elemento que saldr  del buffer
    int m_in;           //indice a la posici n en la que entrar  el sig elemento
    int m_cont;         //contador de numero de elementos en buffer
    mutex m_mutex;      //para exclusion mutua
    condition_variable noLleno;
    condition_variable noVacio;
public:
    BufferLimitado(int tam);
    ~BufferLimitado();
    void mete(double valor);
    double saca();
};

#endif // BUFFER_H
