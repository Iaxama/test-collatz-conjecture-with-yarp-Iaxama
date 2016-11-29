#include <Client.h>

int main(int argc, char * argv[]){

    /* initialize yarp network */
    yarp::os::Network network;
    network.init();

    /* create the module */
    Client client;

    /* prepare and configure the resource finder */
    yarp::os::ResourceFinder rf;
    rf.setVerbose( true );
    rf.configure( argc, argv );

    client.runModule(rf);
    network.fini();

    return 0;
}
