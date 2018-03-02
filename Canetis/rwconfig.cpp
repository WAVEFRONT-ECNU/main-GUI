#include "rwconfig.h"

libconfig::Config mainconfig;

rwConfig::rwConfig()
{

}

void rwConfig::loadConfig(std::string configpath)
{
    try
    {
        mainconfig.readFile(configpath.c_str());
    }
    catch(libconfig::FileIOException &e)
    {
        std::cout<<"read file [ "<<configpath<< " ] FileIOException"<<std::endl;
        return;
    }
    catch(libconfig::ParseException &e)
    {
        std::cout<<"read file [ "<<configpath<< " ],ParaseException: "<<e.getError()<<",line:"<<e.getLine()<<std::endl;
        return;
    }
    catch(...)
    {
        std::cout<<"read file ["<<configpath<< " ] unknown exception"<<std::endl;
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
    root.add(id, libconfig::Setting::TypeString)=value;
}
