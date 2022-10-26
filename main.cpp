#include <iostream>
#include <cmath>

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

#include "Calc.h"

#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class MessageDto : public oatpp::DTO {

  DTO_INIT(MessageDto, DTO /* Extends */)

  DTO_FIELD(Int32, statusCode);   // Status code field
  DTO_FIELD(String, message);     // Message field

};

/**
 * Custom Request Handler
 */
class Handler : public oatpp::web::server::HttpRequestHandler {
private:
  std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;

public:
  Handler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper)
    : m_objectMapper(objectMapper)
  {}

  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
    auto message = MessageDto::createShared();
    message->statusCode = 1024;
    message->message = "Hello DTO!";
    return ResponseFactory::createResponse(Status::CODE_200, message, m_objectMapper);
  }

};

/** 
  * Custom Request Handler
  */

class Handler2 : public oatpp::web::server::HttpRequestHandler {
public:
  std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override {
    return ResponseFactory::createResponse(Status::CODE_200, "Hello World from bakery PW io!");
  }
};


void run() {

  /* 1. Create Router for HTTP requests routing */
  /* 2. Route GET - "/hello" requests to Handler */
  /* 3. Create HTTP connection handler with router */
  /* 4. Create TCP connection provider */
  /* 5. Create server which takes provided TCP connections and passes them to HTTP connection handler */
  /* 6. Print info about server port */  
  /* 7. Run server */

  /* Create json object mapper */
  auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
 
  auto router = oatpp::web::server::HttpRouter::createShared(); //  1
  router->route("GET", "/hello", std::make_shared<Handler2>());  //  2
  router->route("GET", "/", std::make_shared<Handler>(objectMapper /* json object mapper */ ));  //  2

  auto connectionHandler = oatpp::web::server::HttpConnectionHandler::createShared(router); //  3
  
  auto connectionProvider = oatpp::network::tcp::server::ConnectionProvider::createShared({"0.0.0.0", 8000, oatpp::network::Address::IP_4}); //  4

  oatpp::network::Server server(connectionProvider, connectionHandler); //  5
  OATPP_LOGI("cpp web server;", "Server running on port %s", connectionProvider->getProperty("port").getData()); //  6

  server.run(); //  7

}

int main(){
    std::cout << "hello world from PW io ~ cout msg!\n";
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