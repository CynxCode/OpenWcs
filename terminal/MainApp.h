//
// Created by konstantin on 10.08.16.Konsta
//

#ifndef OPENWCS_MAINAPP_H
#define OPENWCS_MAINAPP_H

#include "Poco/Util/Application.h"
#include "Poco/Util/HelpFormatter.h"

class MainApp : public Poco::Util::Application {
 public:
  MainApp();

 protected:
  void initialize(Poco::Util::Application &) override;
  void uninitialize() override;
  void reinitialize(Poco::Util::Application &) override;
  void defineOptions(Poco::Util::OptionSet &) override;
  void handleHelp(const std::string &, const std::string &);
  void handleVersion(const std::string &, const std::string &);
  void handleSnapPicture(const std::string &, const std::string &);
  void handleTimelapse(std::string);
  void handleConfig(const std::string &, const std::string &);
  void handleWebInterface(const std::string &, const std::string &);
  void displayHelp();
  static void displayVersion(std::ostream &);
  void processInternalCLIOptions(std::string);
  int main(const ArgVec &) override;

 private:
  bool _endExecution;
  bool _enableWebInterface;
};


#endif //OPENWCS_MAINAPP_H
