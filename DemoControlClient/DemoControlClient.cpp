#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <sstream>

using boost::asio::ip::tcp;

enum { max_length = 1024 };


int main()
{
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints =
        resolver.resolve(tcp::v4(), "127.0.0.1", "1236");

    tcp::socket s(io_context);
    

    std::stringstream ss;
    std::string input;
    while (true) {
        try {
            boost::asio::connect(s, endpoints);
            break;
        }
        catch(std::exception ex) {
            continue;
        }
    }
    std::cout << "connected. \n";
    while (true) {
        std::cout << "input: ";
        std::cin >> input;
        ss.clear();

        ss << input;
        std::string message = ss.str();
        boost::asio::write(s, boost::asio::buffer(input, input.length()));
        if (input == "exit") {
            break;
        }
    }
    return 0;
}

