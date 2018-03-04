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
    std::string getConfig(std::string id);
    void setConfig(std::string id, std::string value);
private:
    libconfig::Config mainconfig;
    std::string configpath;
};

#endif // RWCONFIG_H
