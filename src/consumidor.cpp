#include "drone.h"
#include "buffer.h"
#include "iostream"
#include <ctime>

void consumidor(int id, BufferLimitado& buffer)
{
    for(int i = 0; i < 100; ++i)
    {
        double valor = buffer.saca();
        std::cout << valor << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    }
}
