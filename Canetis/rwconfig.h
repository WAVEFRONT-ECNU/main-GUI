#ifndef RWCONFIG_H
#define RWCONFIG_H

#include <libconfig.h++>
#include <iostream>
#include <string>

class rwConfig
{
public:
    rwConfig();
    void loadConfig(std::string configpath);
    static libconfig::Config mainconfig;
    std::string getConfig(std::string id);
    void setConfig(std::string id, std::string value);
};

#endif // RWCONFIG_H
