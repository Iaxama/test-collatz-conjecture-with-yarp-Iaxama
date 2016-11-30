#server_interface.thrift
service ServerIDLInterface {
    void start();
    void stop();
    void pause();
    void printFIFO();
    void emptyFIFO();
}