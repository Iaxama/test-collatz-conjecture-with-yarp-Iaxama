//
// Created by miacono on 24/11/16.
//

#ifndef COLLATZ_CONJECTURE_SERVER_H
#define COLLATZ_CONJECTURE_SERVER_H

#include <yarp/os/all.h>
#include <ServerIDLInterface.h>
#include <vocabs.hpp>
#include <queue>

#define PERIOD 0

class Server : public yarp::os::RFModule, public ServerIDLInterface{

private:
//    yarp::os::BufferedPort<yarp::os::Bottle> requestPort;
//    yarp::os::BufferedPort<yarp::os::Bottle> responsePort;
    yarp::os::RpcServer commandPort;
    std::string commandPortName;
    yarp::os::RpcServer serverPort;
    std::string serverPortName;
    std::vector<int> FIFO;
    yarp::os::Bottle request;

    int nResponse;
    int tResponse;
    int counter;
    bool isRunning;
    void computeResponse(int request);
    void sendResponse(int request);

public:

    bool updateModule();
    bool configure(yarp::os::ResourceFinder &rf);
    bool close();
    double getPeriod();

    //Thrift Methods
    void start();
    void stop();
    void pause();
    void printFIFO();
    void emptyFIFO();
};

#endif //COLLATZ_CONJECTURE_SERVER_H
