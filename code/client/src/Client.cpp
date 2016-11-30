#include <Client.h>

bool Client::updateModule(){

    yarp::os::Bottle inputBottle;
    if (responsePort.read(inputBottle)){
        if (inputBottle.get(0).asVocab() != COLLATZ_VOCAB_ITEM) {
            std::cerr << "Client side: Incorrect Identifier received. Ignoring message," << std::endl;
            return true;
        }
        int n = inputBottle.get(1).asInt();
        int t = inputBottle.get(2).asInt();
        std::cout << "Received the pair (" << n << ", " << t << ")" << std::endl;
        collatz_test(n,t);
        readyToSend = true;
        return true;
    }

    readyToSend = false;
    return true;
}

void Client::sendRequest() {
    if (readyToSend) {
        yarp::os::Bottle outputBottle;
        outputBottle.addVocab(COLLATZ_VOCAB_REQ_ITEM);
        outputBottle.addInt(testOutcome);
        requestPort.write(outputBottle);
    } else{
        std::cout << "Client side: Nothing to be sent. Sending 0 request" << std::endl;
    }
}

void Client::collatz_test(int n, int t) {
    if (t==0) {
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
    std::cout << "The test outcome is" << testOutcome << std::endl;
}

bool Client::configure(yarp::os::ResourceFinder &rf){
    std::string moduleName =
            rf.check("name", yarp::os::Value("Client")).asString();
    yarp::os::RFModule::setName(moduleName.c_str());

    rpcPortName =  "/";
    rpcPortName += getName();
    rpcPortName += "/rpc";

    if (!rpcPort.open(rpcPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << rpcPortName << std::endl;
        return false;
    }

    requestPortName =  "/";
    requestPortName += getName();
    requestPortName += "/request:o";

    if (!requestPort.open(requestPortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << requestPortName << std::endl;
        return false;
    }
    responsePortName =  "/";
    responsePortName += getName();
    responsePortName += "/response:i";

    if (!responsePort.open(responsePortName.c_str())) {
        std::cout << getName() << ": Unable to open port " << responsePortName << std::endl;
        return false;
    }
    readyToSend = false;
}

bool Client::close() {
    requestPort.close();
    responsePort.close();
    rpcPort.close();
    return true;
}