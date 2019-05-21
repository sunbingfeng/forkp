#include <iostream>
#include <unistd.h>
#include <cstdlib>

int main(int argc, char* argv[])
{
    
	std::cout << "Start test exec process with tick: " << argv[1] << " !" << std::endl;
	std::size_t tick = std::atoi(argv[1]);
	
	for(;;) {
		std::cout << "exec print " << tick ++ << std::endl;
		::sleep(2);
	}

    return 0;
}

