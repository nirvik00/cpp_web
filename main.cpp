#include <iostream>
#include <cmath>


#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "Calc.h"

/** 
 * Custom Request Handler
 */
class Handler : public oatpp::web::server::HttpRequestHandler {
public:

  /**
   * Handle incoming request and return outgoing response.
   */
  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
    return ResponseFactory::createResponse(Status::CODE_200, "Hello World from PW io!");
  }

};


void run() {

  /* Create Router for HTTP requests routing */
  auto router = oatpp::web::server::HttpRouter::createShared();

   /* Route GET - "/hello" requests to Handler */
  router->route("GET", "/hello", std::make_shared<Handler>());

  /* Create HTTP connection handler with router */
  auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router);

  /* Create TCP connection provider */
  auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4});

  /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
  oatpp::network::Server server(connectionProvider, connectionHandler);

  /* Print info about server port */
  OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

  /* Run server */
  server.run();
}

int main(){
    std::cout << "hello world from PW io!\n";
    Calc c;
    int x=c.sum(1, 3);
    std::cout << "sum is: " << x << "\n";

    // c.exp();
    // c.castFunc();

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;
}