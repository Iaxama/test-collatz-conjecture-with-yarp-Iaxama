#include <Server.h>

bool Server::updateModule() {

    yarp::os::Bottle inputBottle;
    serverPort.read(inputBottle, true);

    if (isRunning) {
        if (inputBottle.get(0).asVocab() != COLLATZ_VOCAB_REQ_ITEM) {
            std::cerr << "Server side: Incorrect Identifier received. Ignoring message," << std::endl;
            return true;
        }
        sendResponse(inputBottle.get(1).asInt());
    }
    return true;
}

void Server::sendResponse(int request) {
    computeResponse(request);
    yarp::os::Bottle responseBottle;
    responseBottle.clear();
    responseBottle.addVocab(COLLATZ_VOCAB_ITEM);
    responseBottle.addDouble(nResponse);
    responseBottle.addDouble(tResponse);
    serverPort.reply(responseBottle);
}

void Server::computeResponse(int request) {

    counter++;
    FIFO.push_back(counter);
    tResponse = FIFO.back() - 1;
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

    rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName  += "/commands";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    serverPortName = "/";
    serverPortName += getName();

    if (!serverPort.open(serverPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << serverPortName << std::endl;
        return false;
    }

    counter = 0;
    start();
    return this->yarp().attachAsServer(rpcPort);
}

bool Server::close() {
    serverPort.close();
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
    std::cout << "FIFO = " << std::endl;
    for (std::vector<int>::iterator iterator = FIFO.begin(); iterator != FIFO.end(); ++iterator) {
        std::cout << *iterator << std::endl;
    }
}

void Server::emptyFIFO() {
    std::cout << "Emptying FIFO and reinitializing server" << std::endl;
    FIFO.clear();
    counter = 0;
}

