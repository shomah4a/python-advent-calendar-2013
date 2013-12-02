#!/bin/sh

# g++ test.cpp -o hello.so -shared -fPIC `pkg-config --libs --cflags python` -lboost_python

g++ test.cpp -o hello.so -shared -fPIC `/usr/local/python3.3/bin/python3.3-config --libs --cflags` \
    -L/usr/local/python3.3/lib -lpython3.3m \
    -I/home/shoma/files/Python-3.3.2 \
    -I/home/shoma/downloads/boost_1_55_0 \
    -L/home/shoma/downloads/boost_1_55_0/stage/lib \
    -lboost_python \
    --std=c++11

