#include <Server.h>

bool Server::updateModule() {


    serverPort.read(request, true);

    if (isRunning) {
        yarp::os::Mutex mutex;
        mutex.lock();
        if (request.get(0).asVocab() != COLLATZ_VOCAB_REQ_ITEM) {
            std::cerr << "Server side: Incorrect Identifier received. Ignoring message" << std::endl;
            return true;
        }
        sendResponse(request.get(1).asInt());
        mutex.unlock();
    }
    return true;
}

void Server::sendResponse(int request) {
    computeResponse(request);
    yarp::os::Bottle reply;
    reply.clear();
    reply.addVocab(COLLATZ_VOCAB_ITEM);
    reply.addDouble(nResponse);
    reply.addDouble(tResponse);
    serverPort.reply(reply);
}

void Server::computeResponse(int request) {

    counter++;
    FIFO.push_back(counter);
    tResponse = FIFO.back() - 1;
    nResponse = counter;
    for (std::vector<int>::iterator iterator = FIFO.begin(); iterator != FIFO.end(); ++iterator) {
        if (*iterator == request) {
            FIFO.erase(iterator);
            break;
        }
    }
}

bool Server::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("server")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    commandPortName =  "/";
    commandPortName += getName();
    commandPortName  += "/commands";

    if (!commandPort.open(commandPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << commandPortName << std::endl;
        close();
        return false;
    }

    serverPortName = "/";
    serverPortName += getName();

    if (!serverPort.open(serverPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << serverPortName << std::endl;
        close();
        return false;
    }

    counter = 0;
    start();
    return this->yarp().attachAsServer(commandPort);
}

bool Server::close() {
    serverPort.close();
    commandPort.close();
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
    std::cout << "Server stopping" << std::endl;
    close();
}

void Server::pause() {
    std::cout << "Server in pause" << std::endl;
    isRunning = false;
}

void Server::printFIFO() {
    yarp::os::Mutex mutex;
    mutex.lock();
    std::cout << "FIFO = " << std::endl;
    for (std::vector<int>::iterator iterator = FIFO.begin(); iterator != FIFO.end(); ++iterator) {
        std::cout << *iterator << std::endl;
    }
    mutex.unlock();
}

void Server::emptyFIFO() {
    yarp::os::Mutex mutex;
    mutex.lock();
    std::cout << "Emptying FIFO and reinitializing server" << std::endl;
    FIFO.clear();
    counter = 0;
    mutex.unlock();
}

