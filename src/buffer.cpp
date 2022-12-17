#include "buffer.h"

BufferLimitado::BufferLimitado(int tam) //constructor
    {
        m_tam  = tam;
        m_out  = m_in = 0; //punteros de entrada y salida de buffer apuntan a 0
        m_cont = 0;     //numero de elementos en buffer inicialmente es 0
        m_buf  = new int[tam]; //reserva memoria para guardar tam enteros
    }

    BufferLimitado::~BufferLimitado()   //destructor
    {
        delete[] m_buf; //libera memoria reservada
    }

void BufferLimitado::mete(int valor)
    {
        cout <<"intenta meter"<< endl;
        unique_lock<mutex> unilock(m_mutex);
        noLleno.wait(unilock, [this](){ return m_cont<m_tam;});
        //Si lambda devuelve falso espera. Es decir, espera si est  lleno

        m_buf[m_in] = valor;
        m_in = (m_in + 1) % m_tam;//actualiza posici n de entrada. buffer circular
        ++m_cont;
        cout << "Productor cont=" << m_cont <<  " ha metido " << valor << endl;

        noVacio.notify_one();
    }

int BufferLimitado::saca()
    {
        cout <<"intenta sacar"<< endl;
        unique_lock<mutex> unilock(m_mutex);
        noVacio.wait(unilock, [this](){ return m_cont;}); //espera si est  vacio

        int valor = m_buf[m_out];
        m_out = (m_out + 1) % m_tam;
        --m_cont;
        cout << "Consumidor cont=" << m_cont << " ha sacado " << valor << endl;
        noLleno.notify_one();
        return valor;
    }
