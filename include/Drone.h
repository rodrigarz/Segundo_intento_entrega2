#ifndef DRONE_H
#define DRONE_H
#include "buffer.h"

const int TIEMPO_ARRANQUE = 2;
const int RADIO = 6370000;

struct CoordenadasGPS
{
    double latitud;
    double longuitud;
};

class BufferLimitado;
class Drone
{
public:
   double mHeight{0.0};
   double mBattery{100.0};
   double mDistancia{0};
   double mRecorrido{0};
   BufferLimitado *mBuffer;

public:
    void arrancar();
//    void subirHasta(int h);
//    void bajarHasta(int h2);
//    void aterrizar();
//    double obtenerDistancia();
//    void moverHasta(const &d);

};

#endif // DRONE_H
