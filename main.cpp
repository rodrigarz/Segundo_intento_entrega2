#include <iostream>
#include "Drone.h"
#include "buffer.h"
#include <thread>

using namespace std;

void consumidor(int id, BufferLimitado& buffer);
void productor(int id, BufferLimitado& buffer);


int main()
{
    BufferLimitado buffer(10);

    thread p0(productor, 0, ref(buffer));
    thread c0(consumidor, 0, ref(buffer));
    p0.join();
    c0.join();
    cout << "Prueba repositorio" << endl;
    return 0;
}
