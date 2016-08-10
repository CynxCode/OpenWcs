//
// Created by konstantin on 10.08.16.
//

#include "MainApp.h"

#include <iostream>
#include <sstream>

#include "Picture.h"

#include <unistd.h>

using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;

MainApp::MainApp()
    : _endExecution(false)
{
}

void MainApp::initialize(Application &self)
{
    loadConfiguration(); // load default configuration files, if present
    Application::initialize(self);
    // add your own initialization code here
}

void MainApp::uninitialize()
{
    // add your own uninitialization code here
    Application::uninitialize();
}

void MainApp::reinitialize(Application &self)
{
    Application::reinitialize(self);
    // add your own reinitialization code here
}

void MainApp::defineOptions(OptionSet &options)
{
    Application::defineOptions(options);

    options.addOption(
        Option("help", "h", "display help information on command line arguments")
            .required(false)
            .repeatable(false)
            .callback(OptionCallback<MainApp>(this, &MainApp::handleHelp)));

    options.addOption(
        Option("snapPicture", "P", "snaps a picture and save it to file")
            .required(false)
            .repeatable(false)
            .argument("file", false)
            .callback(OptionCallback<MainApp>(this, &MainApp::handleSnapPicture)));

    options.addOption(
        Option("config-file", "f", "load configuration data from a file")
            .required(false)
            .repeatable(true)
            .argument("file")
            .callback(OptionCallback<MainApp>(this, &MainApp::handleConfig)));

}

void MainApp::handleHelp(const std::string &name, const std::string &value)
{
    _endExecution = true;
    displayHelp();
    stopOptionsProcessing();
}

void MainApp::handleSnapPicture(const std::string &name, const std::string &value)
{
    _endExecution = true;

    try {
        Picture picture;
        usleep(500000); //TODO: anderen Befehl finden!
        picture.snap();
        picture.displayDate();
        picture.save(value);
    }

    catch (Poco::Exception &exc) {
        std::cerr << exc.displayText() << std::endl;
    }
    stopOptionsProcessing();

}

void MainApp::handleConfig(const std::string &name, const std::string &value)
{
    loadConfiguration(value); //TODO: Load configuration
}

void MainApp::displayHelp()
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("An application for webcams");
    helpFormatter.format(std::cout);
}

int MainApp::main(const ArgVec &args)
{
    if (!_endExecution) {
        std::cout << "To be done." << std::endl;
    }
    return Application::EXIT_OK;
}
