#include "Vector.h"
#include <iostream>


int main() {
	Vector < const char* > T;
	T.PushBack("Vector1");
	T.PushBack("Vector2");
	T.PushBack("Vector3");
	T.PushBack("Vector4");
	T.PushBack("Vector5");
	T.PushBack("Vector6");
	T.PushBack("Vector7");
	for (size_t i = 0; i < T.Length(); i++) {
		std::cout << T[i] << "\n";
	}
	std::cout << "Max size  -> " << T.Size() << std::endl;
	std::cout << "Used size -> " << T.Length() << std::endl;

}