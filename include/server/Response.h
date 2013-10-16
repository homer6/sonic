

#include <string>
#include <map>

#include "fcgi_config.h"
#include "fcgiapp.h"

using std::string;



class Response{

    public:        
        Response();

        void send();


    private:
        int response_code;
        string message_body;

};
