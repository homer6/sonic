
#include "server/SonicService.h"

#include <iostream>



SonicService::SonicService( int number_of_threads, std::string data_path )
    :number_of_threads(number_of_threads), data_path(data_path)
{




}



void SonicService::start(){


    using namespace std;


    cout << "Hello from sonic" << endl;


}
