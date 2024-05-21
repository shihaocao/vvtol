#include <named_pipe_manager.hpp>

NamedPipeManager::NamedPipeManager(const std::string &pipe_path) : pipe_path_(pipe_path)
{
    pipe_.open(pipe_path_, std::ofstream::out);
    if (!pipe_.is_open())
    {
        throw std::runtime_error("Failed to open named pipe.");
    }
}

NamedPipeManager::~NamedPipeManager()
{
    if (pipe_.is_open())
    {
        pipe_.close();
        std::cout << "Named pipe closed." << std::endl;
    }
}

void NamedPipeManager::writeToPipe(const std::string &data)
{
    if (pipe_.is_open())
    {
        pipe_ << data << std::endl;
        pipe_.flush();
    }
}

void NamedPipeManager::writeToPipe(const uint8_t *buffer, size_t length)
{
    if (pipe_.is_open())
    {
        pipe_.write(reinterpret_cast<const char *>(buffer), length);
        pipe_.flush();
    }
}