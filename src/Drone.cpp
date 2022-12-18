#include <thread>
#include "drone.h"
#include <cmath>
#include <chrono>
#include <iostream>
#include "buffer.h"
#include <mutex>


using namespace std;

mutex mu;

void Drone::arrancar()
{
    cout << "Arranque del drone" << endl;
    for(int i = 0; i < TIEMPO_ARRANQUE; i++)
    {
        //mu.lock();
        mHeight = 0;
        mDistancia = 10;
        mRecorrido = 20;
        mBuffer->mete(mHeight);
        mBuffer->mete(mBattery);
        mBuffer->mete(mDistancia);
        mBuffer->mete(mRecorrido);
        //mu.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mBattery -= 1;
    }

}

//void Drone::subirHasta(int altura)
//{
//    std::cout << "Ascendiendo a "<< altura << " metros..."<< std::endl;
//    std::cout << "\n" << std::endl;
//    cout << "Bateria     Altura      TimeStamp" << endl;
//    cout << "_________________________________" <<endl;
//    while(mHeight<altura)
//    {
//        mHeight += 1;
//        mBattery -= 1;
//        time(&mTimeStamp);
//        cout << mBattery << "           " << mHeight << "           " << mTimeStamp << endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //espera un segundo. No hace nada.
//    }
//}
//
//void Drone::bajarHasta(int altura)
//{
//        if(altura)
//    {
//        //para no imprimir "descendiento a 0 metros..." (aterrizaje)
//        std::cout << "Descendiendo a "<< altura << " metros..."<< std::endl;
//        std::cout << "\n" << std::endl;
//    }
//
//    cout << "Bateria     Altura      TimeStamp" << endl;
//    cout << "_________________________________" <<endl;
//
//    while(mHeight>altura)
//    {
//        mHeight -= 1;
//        mBattery -= 1;
//        time(&mTimeStamp);
//        cout << mBattery << "           " << mHeight << "           " << mTimeStamp << endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //espera un segundo. No hace nada.
//    }
//}
//
//
//void Drone::aterrizar()
//{
//    std::cout << "Aterrizando..." << std::endl;
//    std::cout << "\n" << std::endl;
//    std::cout << "Aterrizaje" <<std::endl;
//    bajarHasta(0);
//
//    std::cout <<"Completado" << std::endl;
//}
//
//
//double Drone::obtenerDistancia()
//{
//     CoordenadasGPS origen, destino, origenRad, destinoRad;
//
//    double r = 6370000;
//
//    std::cout << "Introduzca coordenadas de origen, latitud y longuitud, en grados: " << std::endl;
//    std::cin >> origen.latitud;
//    std::cin >> origen.longuitud;
//
//    std::cout << "Introduzca coordenadas de destino, latitud y longuitud, en grados: " << std::endl;
//    std::cin >> destino.latitud;
//    std::cin >> destino.longuitud;
//
//    origenRad.latitud = origen.latitud * M_PI/180;
//    origenRad.longuitud = origen.longuitud * M_PI/180;
//    destinoRad.latitud = destino.latitud * M_PI/180;
//    destinoRad.longuitud = destino.longuitud * M_PI/180;
//
//    double di = 2*r*asin(sqrt( pow(sin( (destinoRad.latitud - origenRad.latitud)/2),2) + cos(origenRad.latitud)*cos(destinoRad.latitud)*pow(sin((destinoRad.longuitud - origenRad.longuitud)/2),2)));
//
//    std::cout << "La distancia que recorreremos es de " << di << " metros" <<std::endl;
//
//    mDistancia = di;
//
//    return(di);
//}
//
//void Drone::moverHasta(const &d)
//{
//    double recorrido = 0;
//    int veloc = 15;
//    cout << "Bateria     Altura      Distancia      TimeStamp" << endl;
//    cout << "________________________________________________" <<endl;
//    while(d >= recorrido)
//    {
//        if (mBattery <= mHeight)
//        {
//            std::cout << "La batería se esta agotando, aterrizando automaticamente" << std::endl;
//            aterrizar();
//            std::cout << "Batería agotada " <<endl;
//            break;
//        }
//        recorrido = recorrido +veloc;
//        mBattery -= 1;
//        time(&mTimeStamp);
//        cout << mBattery << "         " << mHeight << "           " << recorrido << "           " << mTimeStamp <<endl;
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    }
//}
