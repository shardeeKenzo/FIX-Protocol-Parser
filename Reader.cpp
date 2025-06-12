//
// Created by shardee_ on 6/4/25.
//

#include "Reader.h"

#include <fstream>
#include <iostream>


std::deque<std::string> Reader::extractMessages(const std::string& path) const {

    std::ifstream f(path);

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return {};
    }

    std::deque<std::string> messages {};
    std::string msg {};

    while (getline(f, msg)) {
        messages.push_back(msg);
    }

    return messages;
}
