//
// Created by konstantin on 10.08.16.
//

#include "MainApp.h"

#include "Poco/Util/OptionProcessor.h"
#include "Poco/StringTokenizer.h"

#include "Picture.h"
#include "timer/Timelapse.h"

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
        Option("snap-picture", "P", "snaps a picture and save it to file")
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

    options.addOption(
        Option("cmd-only", "c", "disables the web interface")
            .required(false)
            .repeatable(false));

    options.addOption(
        Option("version", "v", "displays the software version")
            .required(false)
            .repeatable(false)
            .callback(OptionCallback<MainApp>(this, &MainApp::handleVersion)));
}

void MainApp::handleHelp(const std::string &name, const std::string &value)
{
    _endExecution = true;
    displayHelp();
    stopOptionsProcessing();
}

void MainApp::handleVersion(const std::string &name, const std::string &value)
{
    _endExecution = true;
    displayVersion();
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
        picture.save(value, "");
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
    helpFormatter.setUsage("[FLAGS]");
    helpFormatter.setHeader("An application for webcams");
    helpFormatter.format(std::cout);
}

void MainApp::displayVersion()
{
    std::cout << "OpenWcs v0.1-dev" << std::endl;
}

void MainApp::processInternalCLIOptions(std::string input)
{
    Poco::StringTokenizer splitInput(input, " ", Poco::StringTokenizer::TOK_IGNORE_EMPTY);
    std::string option = splitInput[0];
    if(option == "")
        return;
    else if(option == "timelapse")
        std::cout << "Starting timelapse..." << std::endl; //Autoptr timelapse = new Timelapse(input)
    else if (option == "picture") {
        try {
            Picture picture;
            picture.setVerbose(true);
            usleep(500000); //TODO: anderen Befehl finden!
            picture.snap();
            picture.displayDate();
            picture.save("", "");
        }

        catch (Poco::Exception &exc) {
            std::cerr << exc.displayText() << std::endl;
        }
    }
    else if(option == "quit" || option == "exit")
        _endExecution = true;
    else
        std::cout << "Unknown argument" << std::endl;
}

int MainApp::main(const ArgVec &args)
{
    while (!_endExecution) {
        std::string input;
        std::cout << "openwcs>";
        getline(std::cin, input);
        processInternalCLIOptions(input);
    }
    return Application::EXIT_OK;
}