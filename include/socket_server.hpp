#ifndef SOCKET_SERVER_HPP
#define SOCKET_SERVER_HPP

#include <iostream>
#include <string>

class SocketServer {
public:
    SocketServer();
    ~SocketServer();

    void start();
    void stop();
    void processRequest(const std::string& request);

private:
    // Add your private members here

};

#endif // SOCKET_SERVER_HPP
