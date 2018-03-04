#include "rwconfig.h"

rwConfig::rwConfig()
{
    configpath = "./config.cfg";
    loadConfig(configpath);
}

libconfig::Config mainconfig;
std::string configpath;

void rwConfig::loadConfig(std::string configpath)
{
    try
    {
        mainconfig.readFile(configpath.c_str());
    }
    catch(libconfig::FileIOException &e)
    {
        std::cerr<<"read file [ "<<configpath<< " ] FileIOException"<<std::endl;
        return;
    }
    catch(libconfig::ParseException &e)
    {
        std::cerr<<"read file [ "<<configpath<< " ],ParaseException: "<<e.getError()<<",line:"<<e.getLine()<<std::endl;
        return;
    }
    catch(...)
    {
        std::cerr<<"read file ["<<configpath<< " ] unknown exception"<<std::endl;
        return;
    }
}

std::string rwConfig::getConfig(std::string id)
{
    try
    {
        std::string str = mainconfig.lookup(id);
        return str;
    }
    catch(...)
    {
        std::cout<<"Get String id "<<id<<" failed ..."<<std::endl;
        return "ERR";
    }
}

void rwConfig::setConfig(std::string id, std::string value)
{
    libconfig::Setting &root = mainconfig.getRoot();
    try
    {
        if(root.exists(id))
        {
            libconfig::Setting &option = root.lookup(id);
            option = value;
        }
        else {
            root.add(id, libconfig::Setting::TypeString)=value;
        }

        mainconfig.writeFile(configpath.c_str());
        std::cout << "New configuration successfully written."<< std::endl;
    }
    catch( libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while writing file."<< std::endl;
        return;
    }
    catch(std::exception &e)
    {
        std::cerr << "Error while writing file."<<e.what()<< std::endl;
    }
}
