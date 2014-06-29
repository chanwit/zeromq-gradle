#include <zmq.hpp>
#include <string>
#include <iostream>

int main () {
    //  Prepare our context and socket
    zmq::context_t context(1);
    zmq::socket_t  socket(context, ZMQ_REQ);

    std::cout << "Connecting to hello world server ..." << std::endl;
    socket.connect ("tcp://localhost:5555");

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {

        // buffer size of request is 6 for {5, "H","e","l","l","o"}
        zmq::message_t request(6);

        // request.data() is the pointer to buffer
        // so, we are copying "Hello" to that buffer. 5 is the length
        memcpy ((void *) request.data(), "Hello", 5);

        std::cout << "Sending Hello " << request_nbr << "…" << std::endl;

        // Send out the request
        socket.send(request);

        //  Get the reply.
        zmq::message_t reply;
        socket.recv(&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }
    return 0;
}