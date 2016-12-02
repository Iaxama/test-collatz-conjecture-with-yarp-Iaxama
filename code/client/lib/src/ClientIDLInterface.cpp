// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <ClientIDLInterface.h>
#include <yarp/os/idl/WireTypes.h>



class ClientIDLInterface_sendRequest : public yarp::os::Portable {
public:
  bool _return;
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ClientIDLInterface_autoSendRequest : public yarp::os::Portable {
public:
  double period;
  bool _return;
  void init(const double period);
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ClientIDLInterface_stopSendRequest : public yarp::os::Portable {
public:
  bool _return;
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

bool ClientIDLInterface_sendRequest::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("sendRequest",1,1)) return false;
  return true;
}

bool ClientIDLInterface_sendRequest::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void ClientIDLInterface_sendRequest::init() {
  _return = false;
}

bool ClientIDLInterface_autoSendRequest::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(2)) return false;
  if (!writer.writeTag("autoSendRequest",1,1)) return false;
  if (!writer.writeDouble(period)) return false;
  return true;
}

bool ClientIDLInterface_autoSendRequest::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void ClientIDLInterface_autoSendRequest::init(const double period) {
  _return = false;
  this->period = period;
}

bool ClientIDLInterface_stopSendRequest::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("stopSendRequest",1,1)) return false;
  return true;
}

bool ClientIDLInterface_stopSendRequest::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  if (!reader.readBool(_return)) {
    reader.fail();
    return false;
  }
  return true;
}

void ClientIDLInterface_stopSendRequest::init() {
  _return = false;
}

ClientIDLInterface::ClientIDLInterface() {
  yarp().setOwner(*this);
}
bool ClientIDLInterface::sendRequest() {
  bool _return = false;
  ClientIDLInterface_sendRequest helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool ClientIDLInterface::sendRequest()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool ClientIDLInterface::autoSendRequest(const double period) {
  bool _return = false;
  ClientIDLInterface_autoSendRequest helper;
  helper.init(period);
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool ClientIDLInterface::autoSendRequest(const double period)");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}
bool ClientIDLInterface::stopSendRequest() {
  bool _return = false;
  ClientIDLInterface_stopSendRequest helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","bool ClientIDLInterface::stopSendRequest()");
  }
  bool ok = yarp().write(helper,helper);
  return ok?helper._return:_return;
}

bool ClientIDLInterface::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  bool direct = (tag=="__direct__");
  if (direct) tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "sendRequest") {
      bool _return;
      _return = sendRequest();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "autoSendRequest") {
      double period;
      if (!reader.readDouble(period)) {
        reader.fail();
        return false;
      }
      bool _return;
      _return = autoSendRequest(period);
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "stopSendRequest") {
      bool _return;
      _return = stopSendRequest();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(1)) return false;
        if (!writer.writeBool(_return)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "help") {
      std::string functionName;
      if (!reader.readString(functionName)) {
        functionName = "--all";
      }
      std::vector<std::string> _return=help(functionName);
      yarp::os::idl::WireWriter writer(reader);
        if (!writer.isNull()) {
          if (!writer.writeListHeader(2)) return false;
          if (!writer.writeTag("many",1, 0)) return false;
          if (!writer.writeListBegin(BOTTLE_TAG_INT, static_cast<uint32_t>(_return.size()))) return false;
          std::vector<std::string> ::iterator _iterHelp;
          for (_iterHelp = _return.begin(); _iterHelp != _return.end(); ++_iterHelp)
          {
            if (!writer.writeString(*_iterHelp)) return false;
           }
          if (!writer.writeListEnd()) return false;
        }
      reader.accept();
      return true;
    }
    if (reader.noMore()) { reader.fail(); return false; }
    yarp::os::ConstString next_tag = reader.readTag();
    if (next_tag=="") break;
    tag = tag + "_" + next_tag;
  }
  return false;
}

std::vector<std::string> ClientIDLInterface::help(const std::string& functionName) {
  bool showAll=(functionName=="--all");
  std::vector<std::string> helpString;
  if(showAll) {
    helpString.push_back("*** Available commands:");
    helpString.push_back("sendRequest");
    helpString.push_back("autoSendRequest");
    helpString.push_back("stopSendRequest");
    helpString.push_back("help");
  }
  else {
    if (functionName=="sendRequest") {
      helpString.push_back("bool sendRequest() ");
    }
    if (functionName=="autoSendRequest") {
      helpString.push_back("bool autoSendRequest(const double period) ");
    }
    if (functionName=="stopSendRequest") {
      helpString.push_back("bool stopSendRequest() ");
    }
    if (functionName=="help") {
      helpString.push_back("std::vector<std::string> help(const std::string& functionName=\"--all\")");
      helpString.push_back("Return list of available commands, or help message for a specific function");
      helpString.push_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
      helpString.push_back("@return list of strings (one string per line)");
    }
  }
  if ( helpString.empty()) helpString.push_back("Command not found");
  return helpString;
}


