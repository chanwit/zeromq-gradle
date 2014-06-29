ZeroMQ Gradle Template
======================

(c) Chanwit Kaewkasi / SUT

This is a template for compiling ZeroMQ-based multi-projects with Gradle.
It uses the Gradle's `cpp` plugin to enable C++ compilation.

Instructions
------------

  * Install ZeroMQ


    tar xf zeromq-4.0.4.tar.gz
    cd zeromq-4.0.4
    ./autogen.sh
    make && make install


  * Install ZeroMQ C++ binding


    cp zmq.hpp /usr/local/include/.


  * Build the project


    gradle clean mainExecutable
