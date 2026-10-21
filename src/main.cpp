#include <iostream>


#include "drone.h"

int main() {
	std::cout << "=== Actor setup ===" << std::endl;	
	
	Vec3 x(1.0f, 0.0f, 0.0f);
	Vec3 y(1.0f, 3.0f, -5.0f);

	Vec3 g = x.cross(y);
	
	std::cout << g.y() << std::endl;
	
	std::cout << x << std::endl;

	std::cout << x.normalize() << std::endl;


	return 0;
}
