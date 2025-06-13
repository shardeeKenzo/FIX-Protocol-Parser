//
// Created by shardee_ on 6/4/25.
//

#ifndef FIXPARSER_H
#define FIXPARSER_H
#include <cstdint>
#include <deque>
#include <string>
#include <unordered_map>
#include <utility>

class FIXParser {
private:
    std::pair<std::string, std::string> decode_single_tag_and_value(std::string& msg);
public:
    FIXParser()= default;

    std::unordered_map<std::string, std::string> decode_single_fix_msg(std::string& msg);
};



#endif //FIXPARSER_H
