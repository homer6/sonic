

#include <string>



class SonicService{

    public:
        SonicService( int number_of_threads, std::string data_path );


        void start();


    private:
        int number_of_threads;
        std::string data_path;

};
