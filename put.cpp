#include <iostream>
namespace abc {


int put(const char *in)
{
	int out = 0;
	
	for(int i = 0; in[i] != '\0'; i++){
		std::cout << in[i];
	}
	return out;
}
}

using namespace abc;
using namespace std;

int main(int argc, char **argv){

	int i;
	
	put("Hello World!\n");
	cout << "Zeichenkette hat " << i << " Zeichen." << std::endl;
		
	return 0;
}
