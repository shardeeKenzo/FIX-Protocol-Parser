//
// Created by shardee_ on 6/4/25.
//

#ifndef READER_H
#define READER_H
#include <deque>
#include <string>
#include <utility>

class Reader {
private:

    std::string path;

public:
    explicit Reader(std::string  path_) : path {std::move(path_)}
    {}

    [[nodiscard]] std::deque<std::string> extractMessages() const;
};

#endif //READER_H
