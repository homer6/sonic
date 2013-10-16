
#include "server/SonicService.h"
#include "server/Request.h"

#include <iostream>

#include "fcgiapp.h"


SonicService::SonicService( int number_of_threads, std::string data_path )
    :number_of_threads(number_of_threads), data_path(data_path)
{




}



void SonicService::start(){


    FCGX_Request fcgi_request;
    FCGX_InitRequest( &fcgi_request, 0, 0 );
    int request_count;
    Request request( fcgi_request );

    using namespace std;

    for(;;){

        request_count = FCGX_Accept_r( &fcgi_request );
        if( request_count < 0 ){
            continue;
        }

        request.load();


    }




    cout << "Hello from sonic" << endl;


}





