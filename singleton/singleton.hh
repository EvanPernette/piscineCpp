#pragma once

#include <cassert>
#include <iostream>
#include <memory>

template <typename T>
class Singleton
{
public:
    static T* instance()
    {
        static std::unique_ptr<T> instance_(new T);
        return instance_.get();
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

class Logger : public Singleton<Logger>
{
public:
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

private:
    Logger() = default;
    friend class Singleton<Logger>;
};