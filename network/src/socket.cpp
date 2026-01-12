#include <network/socket.h>

#include <iostream>


namespace network
{
bool Socket::connect(const std::string &ip, int port)
{
  std::cout << "connet to " << ip << ':' << port << '\n';
  return true;
}
}  // namespace network