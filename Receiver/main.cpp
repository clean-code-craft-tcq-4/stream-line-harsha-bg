#include <iostream>
#include "includes/Processor.hpp"

// Driver Code
int main()
{
    //assuming there are 1000 characters on console
    // clear buffer before taking
	char str[1000] = {0};
	
	std::cin.read(str, 1000);
    Processor input_processor;
    input_processor.processInput(str);  
    input_processor.printProcessedInput();
	return 0;
}
