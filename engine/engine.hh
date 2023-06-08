#pragma once

class Engine
{
private:
    int fuel_;

public:
    Engine(int fuel);

public:
    bool start();

public:
    void stop() const;

public:
    void use(int consumed);

public:
    void fill(int fuel);
};