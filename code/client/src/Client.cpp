#include <Client.h>

bool Client::updateModule(){
//    sendRequest();
    return true;
}

void Client::sendRequest() {

    yarp::os::Bottle outputBottle;
    yarp::os::Bottle inputBottle;
    outputBottle.addVocab(COLLATZ_VOCAB_REQ_ITEM);
    outputBottle.addInt(n);
    if (testOutcome == 0) {
        std::cout << "Client side: Test unsuccessful. Sending 0 request" << std::endl;
    }
    std::cout << "Sending request " << n << std::endl;
    clientPort.write(outputBottle,inputBottle);

    if (inputBottle.get(0).asVocab() != COLLATZ_VOCAB_ITEM) {
        std::cerr << "Client side: Incorrect Identifier received. Ignoring message," << std::endl;
        return;
    }
    n = inputBottle.get(1).asInt();
    t = inputBottle.get(2).asInt();
    std::cout << "Received the pair (" << n << ", " << t << ")" << std::endl;
    collatz_test(n,t);

}

void Client::collatz_test(int n, int t) {

    if (t <= 0) {
        std::cout << "Threshold 0 would not converge. Using 1 instead" << std::endl;
        t = 1;
    }
    while (n > t){
        if (n % 2 == 0){
            n /= 2;
        } else {
            n *=3;
            n++;
        }
    }
    testOutcome = n;
    std::cout << "The test outcome is " << testOutcome << std::endl;
}

bool Client::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Client")).asString();

    std::string id = rf.check("id",yarp::os::Value(0)).asString();
    moduleName += "_";
    moduleName += id;
    std::cout << "moduleName = " << moduleName << std::endl;
    yarp::os::RFModule::setName(moduleName.c_str());



    rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName += "/commands";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    clientPortName =  "/";
    clientPortName += getName();

    if (!clientPort.open(clientPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << clientPortName << std::endl;
        return false;
    }

    testOutcome = 0;
    this->yarp().attachAsServer(rpcPort);
    return true;
}

bool Client::close() {
    clientPort.close();
    rpcPort.close();
    return true;
}