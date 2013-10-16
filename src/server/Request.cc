
#include "server/Request.h"


Request::Request(){


}



Request::Request( FCGX_Request& fcgi_request )
    :fcgi_request(fcgi_request)
{


}


void Request::clear(){

    this->environment_variables.clear();

}



void Request::load(){

    this->clear();

    this->environment_variables[ "query_string" ] = FCGX_GetParam( "QUERY_STRING", this->fcgi_request.envp );
    this->environment_variables[ "request_method" ] = FCGX_GetParam( "REQUEST_METHOD", this->fcgi_request.envp );
    this->environment_variables[ "content_type" ] = FCGX_GetParam( "CONTENT_TYPE", this->fcgi_request.envp );
    this->environment_variables[ "content_length" ] = FCGX_GetParam( "CONTENT_LENGTH", this->fcgi_request.envp );
    this->environment_variables[ "script_filename" ] = FCGX_GetParam( "SCRIPT_FILENAME", this->fcgi_request.envp );
    this->environment_variables[ "script_name" ] = FCGX_GetParam( "SCRIPT_NAME", this->fcgi_request.envp );
    this->environment_variables[ "request_uri" ] = FCGX_GetParam( "REQUEST_URI", this->fcgi_request.envp );
    this->environment_variables[ "document_uri" ] = FCGX_GetParam( "DOCUMENT_URI", this->fcgi_request.envp );
    this->environment_variables[ "document_root" ] = FCGX_GetParam( "DOCUMENT_ROOT", this->fcgi_request.envp );
    this->environment_variables[ "server_protocol" ] = FCGX_GetParam( "SERVER_PROTOCOL", this->fcgi_request.envp );
    this->environment_variables[ "remote_addr" ] = FCGX_GetParam( "REMOTE_ADDR", this->fcgi_request.envp );
    this->environment_variables[ "remote_port" ] = FCGX_GetParam( "REMOTE_PORT", this->fcgi_request.envp );
    this->environment_variables[ "server_addr" ] = FCGX_GetParam( "SERVER_ADDR", this->fcgi_request.envp );
    this->environment_variables[ "server_port" ] = FCGX_GetParam( "SERVER_PORT", this->fcgi_request.envp );
    this->environment_variables[ "server_name" ] = FCGX_GetParam( "SERVER_NAME", this->fcgi_request.envp );

}

