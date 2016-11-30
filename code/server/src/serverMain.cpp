#include <Server.h>

int main(int argc, char * argv[]){

    /* initialize yarp network */
    yarp::os::Network::init();

    /* create the module */
    Server server;

    /* prepare and configure the resource finder */
    yarp::os::ResourceFinder rf;
    rf.setVerbose( true );
    rf.configure( argc, argv );

    /* run the module: runModule() calls configure first and, if successful, it then runs */

    server.runModule(rf);
    yarp::os::Network::fini();

    return 0;
}

