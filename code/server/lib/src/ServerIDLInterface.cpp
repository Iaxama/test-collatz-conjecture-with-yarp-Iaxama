// This is an automatically-generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <ServerIDLInterface.h>
#include <yarp/os/idl/WireTypes.h>



class ServerIDLInterface_start : public yarp::os::Portable {
public:
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ServerIDLInterface_stop : public yarp::os::Portable {
public:
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ServerIDLInterface_pause : public yarp::os::Portable {
public:
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ServerIDLInterface_printFIFO : public yarp::os::Portable {
public:
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

class ServerIDLInterface_emptyFIFO : public yarp::os::Portable {
public:
  void init();
  virtual bool write(yarp::os::ConnectionWriter& connection);
  virtual bool read(yarp::os::ConnectionReader& connection);
};

bool ServerIDLInterface_start::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("start",1,1)) return false;
  return true;
}

bool ServerIDLInterface_start::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ServerIDLInterface_start::init() {
}

bool ServerIDLInterface_stop::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("stop",1,1)) return false;
  return true;
}

bool ServerIDLInterface_stop::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ServerIDLInterface_stop::init() {
}

bool ServerIDLInterface_pause::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("pause",1,1)) return false;
  return true;
}

bool ServerIDLInterface_pause::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ServerIDLInterface_pause::init() {
}

bool ServerIDLInterface_printFIFO::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("printFIFO",1,1)) return false;
  return true;
}

bool ServerIDLInterface_printFIFO::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ServerIDLInterface_printFIFO::init() {
}

bool ServerIDLInterface_emptyFIFO::write(yarp::os::ConnectionWriter& connection) {
  yarp::os::idl::WireWriter writer(connection);
  if (!writer.writeListHeader(1)) return false;
  if (!writer.writeTag("emptyFIFO",1,1)) return false;
  return true;
}

bool ServerIDLInterface_emptyFIFO::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  if (!reader.readListReturn()) return false;
  return true;
}

void ServerIDLInterface_emptyFIFO::init() {
}

ServerIDLInterface::ServerIDLInterface() {
  yarp().setOwner(*this);
}
void ServerIDLInterface::start() {
  ServerIDLInterface_start helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ServerIDLInterface::start()");
  }
  yarp().write(helper,helper);
}
void ServerIDLInterface::stop() {
  ServerIDLInterface_stop helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ServerIDLInterface::stop()");
  }
  yarp().write(helper,helper);
}
void ServerIDLInterface::pause() {
  ServerIDLInterface_pause helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ServerIDLInterface::pause()");
  }
  yarp().write(helper,helper);
}
void ServerIDLInterface::printFIFO() {
  ServerIDLInterface_printFIFO helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ServerIDLInterface::printFIFO()");
  }
  yarp().write(helper,helper);
}
void ServerIDLInterface::emptyFIFO() {
  ServerIDLInterface_emptyFIFO helper;
  helper.init();
  if (!yarp().canWrite()) {
    yError("Missing server method '%s'?","void ServerIDLInterface::emptyFIFO()");
  }
  yarp().write(helper,helper);
}

bool ServerIDLInterface::read(yarp::os::ConnectionReader& connection) {
  yarp::os::idl::WireReader reader(connection);
  reader.expectAccept();
  if (!reader.readListHeader()) { reader.fail(); return false; }
  yarp::os::ConstString tag = reader.readTag();
  bool direct = (tag=="__direct__");
  if (direct) tag = reader.readTag();
  while (!reader.isError()) {
    // TODO: use quick lookup, this is just a test
    if (tag == "start") {
      start();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "stop") {
      stop();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "pause") {
      pause();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "printFIFO") {
      printFIFO();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
      }
      reader.accept();
      return true;
    }
    if (tag == "emptyFIFO") {
      emptyFIFO();
      yarp::os::idl::WireWriter writer(reader);
      if (!writer.isNull()) {
        if (!writer.writeListHeader(0)) return false;
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

std::vector<std::string> ServerIDLInterface::help(const std::string& functionName) {
  bool showAll=(functionName=="--all");
  std::vector<std::string> helpString;
  if(showAll) {
    helpString.push_back("*** Available commands:");
    helpString.push_back("start");
    helpString.push_back("stop");
    helpString.push_back("pause");
    helpString.push_back("printFIFO");
    helpString.push_back("emptyFIFO");
    helpString.push_back("help");
  }
  else {
    if (functionName=="start") {
      helpString.push_back("void start() ");
    }
    if (functionName=="stop") {
      helpString.push_back("void stop() ");
    }
    if (functionName=="pause") {
      helpString.push_back("void pause() ");
    }
    if (functionName=="printFIFO") {
      helpString.push_back("void printFIFO() ");
    }
    if (functionName=="emptyFIFO") {
      helpString.push_back("void emptyFIFO() ");
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


