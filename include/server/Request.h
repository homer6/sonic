

#include <string>
#include <map>

#include "fcgi_config.h"
#include "fcgiapp.h"

using std::string;
using std::map;


class Request{

    public:        
        Request();
        Request( FCGX_Request& fcgi_request );

        void load();
        void clear();

    private:
        map<string> environment_variables;
        FCGX_Request& fcgi_request;

};
