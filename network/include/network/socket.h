#pragma once
#include <string>

namespace network
{
  class Socket
  {
  public:
    Socket() = default;
    ~Socket() = default;

    bool connect(const std::string &ip, int port);
  };
}