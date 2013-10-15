

#include <iostream>
#include <string>

#include "server/SonicService.h"


using namespace std;


int main( int argc, char** argv ){

    if( argc < 3 ){
        cout << "usage: " + string(argv[0]) + " [data_directory] [number_of_threads]" << endl;
        return 1;
    }

    string data_directory = argv[1];
    int number_of_threads = std::stoi( argv[2] );

    SonicService service( number_of_threads, data_directory );
    service.start();

    return 0;

}
