#include <boost/beast/core.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/http.hpp> // redundant

#include <boost/asio/awaitable.hpp>
#include <boost/asio/ssl.hpp>

#include "nlohmann/json.hpp"

#include <iostream>
#include <string>


class RpcClient
{
    std::string _host;
    boost::asio::ssl::context _ctx;
    boost::beast::ssl_stream<boost::beast::tcp_stream> _stream;

public:
    RpcClient(boost::asio::io_context &ioc, const std::string_view host);
    boost::asio::awaitable<void> connect();
};


RpcClient::RpcClient(boost::asio::io_context &ioc, std::string_view host) : _host{host}, _ctx{boost::asio::ssl::context::tlsv13_client}, _stream{ioc, _ctx}
{
};

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << std::endl;
    }

    double x = 3.14;
    int y = (int)x;
    
    std::cout<<"Hello world!!!!!!!";
    return  0;
}