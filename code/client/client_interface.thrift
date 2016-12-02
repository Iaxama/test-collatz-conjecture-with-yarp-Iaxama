#client_interface.thrift
service ClientIDLInterface {
    bool sendRequest();
    bool autoSendRequest (1:double period);
    bool stopSendRequest();
}