#include "resource.h"
#include <thread>
#include <chrono>

void writeWordsCool(std::string message) {
    const size_t size = message.size();
    std::string finalMessage = message;
    for (int i = 0; i < size; i++)
        finalMessage[i] = ' ';

    for (int i = 0; i < size; i++) {
        finalMessage[i] = message[i];
        std::cout << "\r" << finalMessage;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
}