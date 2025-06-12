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

public:
    Reader() = default;

    std::deque<std::string> extractMessages(const std::string& path) const;
};

#endif //READER_H
