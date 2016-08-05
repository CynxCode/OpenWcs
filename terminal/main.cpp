//
//  main.cpp
//  terminal/src
//
//  Created by Konstantin Papesh and Lorenz Kofler.
//  Copyright 2016 OpenWcs.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#include <iostream>
#include <sstream>

#include "Poco/Util/Application.h"
#include "Poco/Util/HelpFormatter.h"

#include "Picture.h"

using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::AbstractConfiguration;
using Poco::Util::OptionCallback;
using Poco::AutoPtr;

class SampleApp: public Application
    /// This sample demonstrates some of the features of the Util::Application class,
    /// such as configuration file handling and command line arguments processing.
    ///
    /// Try SampleApp --help (on Unix platforms) or SampleApp /help (elsewhere) for
    /// more information.
{
public:
    SampleApp()
        : _endExecution(false)
    {
    }

protected:
    void initialize(Application &self)
    {
        loadConfiguration(); // load default configuration files, if present
        Application::initialize(self);
        // add your own initialization code here
    }

    void uninitialize()
    {
        // add your own uninitialization code here
        Application::uninitialize();
    }

    void reinitialize(Application &self)
    {
        Application::reinitialize(self);
        // add your own reinitialization code here
    }

    void defineOptions(OptionSet &options)
    {
        Application::defineOptions(options);

        options.addOption(
            Option("help", "h", "display help information on command line arguments")
                .required(false)
                .repeatable(false)
                .callback(OptionCallback<SampleApp>(this, &SampleApp::handleHelp)));

        options.addOption(
            Option("snapPicture", "P", "snaps a picture and save it to file")
                .required(false)
                .repeatable(false)
                .argument("file")
                .callback(OptionCallback<SampleApp>(this, &SampleApp::handleSnapPicture)));

        options.addOption(
            Option("config-file", "f", "load configuration data from a file")
                .required(false)
                .repeatable(true)
                .argument("file")
                .callback(OptionCallback<SampleApp>(this, &SampleApp::handleConfig)));

    }

    void handleHelp(const std::string &name, const std::string &value)
    {
        _endExecution = true;
        displayHelp();
        stopOptionsProcessing();
    }

    void handleSnapPicture(const std::string &name, const std::string &value)
    {
        _endExecution = true;
        Picture picture;
        if (picture.init() == picture.OK) {
            picture.snap();
            picture.save(value);
            stopOptionsProcessing();
            std::cout << "Saved " + value + "!" << std::endl;
        }
    }

    void handleConfig(const std::string &name, const std::string &value)
    {
        loadConfiguration(value); //TODO: Load configuration
    }

    void displayHelp()
    {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("An application for webcams");
        helpFormatter.format(std::cout);
    }

    int main(const ArgVec &args)
    {
        if (!_endExecution) {
            std::cout << "To be done." << std::endl;
        }
        return Application::EXIT_OK;
    }

private:
    bool _endExecution;
};

POCO_APP_MAIN(SampleApp)
