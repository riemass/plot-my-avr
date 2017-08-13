#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include "server.hpp"

void read_device(std::ifstream device, std::shared_ptr<Server> server) {
  std::string s;
  while (device >> s) server->send_message(s);
}

void run_server(std::shared_ptr<Server> server) { server->run(); }

int main(int argc, char *argv[]) {
  auto server = std::make_shared<Server>();
  std::ifstream in{"/dev/ttyACM0"};

  std::thread s(run_server, server);

  std::thread t(read_device, std::move(in), server);
  t.detach();
  s.join();

  return 0;
}
