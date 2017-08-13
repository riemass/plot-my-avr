#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <memory>
#include <mutex>
#include <thread>
#include <unordered_set>

#include "crow.h"

class Server {
  public:
  Server();

  void run();

  void send_message(const std::string& data);

  private:
  crow::SimpleApp app;
  std::mutex mtx;
  std::unordered_set<crow::websocket::connection*> users;
};

#endif /* ifndef SERVER_HPP_ */
