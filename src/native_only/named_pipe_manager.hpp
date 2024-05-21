#ifndef NAMEDPIPEMANAGER_HPP
#define NAMEDPIPEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

class NamedPipeManager
{
public:
    NamedPipeManager(const std::string &pipe_path);
    ~NamedPipeManager();

    void writeToPipe(const std::string &data);
    void writeToPipe(const uint8_t *buffer, size_t length);

private:
    std::string pipe_path_;
    std::ofstream pipe_;
};

#endif // NAMEDPIPEMANAGER_HPP
