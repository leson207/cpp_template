#include <simdjson.h>

#include <boost/asio/awaitable.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <string_view>

#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/Logger.h"
#include "quill/sinks/ConsoleSink.h"

// #include <boost/asio/ssl/impl/src.hpp>

class RpcClient
{
    std::string _host;
    boost::asio::ssl::context _ctx;
    boost::beast::ssl_stream<boost::beast::tcp_stream> _stream;

   public:
    RpcClient(boost::asio::io_context& ioc, std::string_view host);
    boost::asio::awaitable<void> connect();
};

RpcClient::RpcClient(boost::asio::io_context& ioc, std::string_view host)
    : _host{host}, _ctx{boost::asio::ssl::context::tlsv13_client}, _stream{ioc, _ctx} {};

int main()
{
    quill::Backend::start();

    quill::Logger* logger = quill::Frontend::create_or_get_logger(
        "root", quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1"));

    LOG_INFO(logger, "Hello from {}!", std::string_view{"Quill"});
}