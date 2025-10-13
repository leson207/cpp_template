#include "cpp_sample/logger.hpp"

#include <boost/asio/awaitable.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>

#include <iostream>
#include <string>


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
    get_logger();
    std::cout << "Hello world!!!!!!!"<<"\n";
    return 0;
}