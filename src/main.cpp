#include <boost/asio/awaitable.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <iostream>
#include <string>

#include "nlohmann/json.hpp"
#include "simdjson.h"

class RpcClient
{
    std::string _host;
    boost::asio::ssl::context _ctx;
    boost::beast::ssl_stream<boost::beast::tcp_stream> _stream;

   public:
    RpcClient(boost::asio::io_context& ioc, std::string_view host);
    auto connect() -> boost::asio::awaitable<void>;
};

RpcClient::RpcClient(boost::asio::io_context& ioc, std::string_view host)
    : _host{host}, _ctx{boost::asio::ssl::context::tlsv13_client}, _stream{ioc, _ctx} {};

auto main() -> int
{
    for (int i = 0; i <= 10; ++i)
    {
        std::cout << i + 100 << "\n";
    }
    std::cout << "Hello world!!!!!!!";
    return 0;
}