#include <Client.h>

int main(int argc, char * argv[]){

    /* initialize yarp network */
    yarp::os::Network network;

    if (!network.checkNetwork()){
        std::cerr << "Yarp Server not running! Module will not start!" << std::endl;
        return -1;
    }
    /* create the module */
    Client client;

    /* prepare and configure the resource finder */
    yarp::os::ResourceFinder rf;
    rf.setVerbose( true );
    rf.configure( argc, argv );

    client.runModule(rf);

    return 0;
}
