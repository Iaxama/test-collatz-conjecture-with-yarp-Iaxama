#include <Server.h>

bool Server::updateModule(){
    yarp::os::Bottle* inputBottle= requestPort.read(false);
    if (inputBottle != NULL && isRunning){
        if (inputBottle->get(0).asVocab() != COLLATZ_VOCAB_REQ_ITEM) {
            std::cerr << "Server side: Incorrect Identifier received. Ignoring message," << std::endl;
            return true;
        }
        sendResponse(inputBottle->get(1).asInt());
    };

    return true;
}

void Server::sendResponse(int request) {
    computeResponse(request);
    yarp::os::Bottle &responseBottle = responsePort.prepare();
    responseBottle.clear();
    responseBottle.addVocab(COLLATZ_VOCAB_ITEM);
    responseBottle.addDouble(nResponse);
    responseBottle.addDouble(tResponse);
    responsePort.write(false);
}

void Server::computeResponse(int request) {

    counter++;
    FIFO.push_back(request);
    tResponse = FIFO.front() - 1;
    nResponse = counter;
    for (std::vector<int>::iterator iterator = FIFO.begin(); iterator != FIFO.end(); ++iterator) {
        if (*iterator == request)
            FIFO.erase(iterator);
    }
}

bool Server::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Server")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    //
    std::string outputPortName =  "/";
    outputPortName += getName();

    if (!rpcPort.open(outputPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << outputPortName << std::endl;
        return false;
    }

    std::string requestPortName = "/";
    requestPortName += getName();
    requestPortName += "/request:i";
    if (!requestPort.open(requestPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << requestPortName << std::endl;
        return false;
    }

    std::string responsePortName = "/";
    responsePortName += getName();
    responsePortName += "/response:o";
    if (!responsePort.open(responsePortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << responsePortName << std::endl;
        return false;
    }

    start();
    return this->yarp().attachAsServer(rpcPort);

}

bool Server::close() {
    requestPort.close();
    responsePort.close();
    rpcPort.close();
    return true;
}

double Server::getPeriod() {
    return PERIOD;
}

void Server::start() {
    isRunning = true;
    std::cout << "ServerRunning" << std::endl;
}

void Server::stop() {
    close();
    std::cout << "Server stopping" << std::endl;
}

void Server::pause() {
    std::cout << "Server in pause" << std::endl;
    isRunning = false;
}

void Server::printFIFO() {
    for (std::vector<int>::iterator iterator = FIFO.begin(); iterator != FIFO.end(); ++iterator) {
        std::cout << "FIFO = " << std::endl;
        std::cout << *iterator << std::endl;
    }
}

void Server::emptyFIFO() {
    std::cout << "Emptying FIFO and reinitializing server" << std::endl;
    FIFO.empty();
    counter = 0;
}


