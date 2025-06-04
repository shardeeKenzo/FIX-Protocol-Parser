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

public:
    FIXParser()= default;

    void decode_data();
    std::unordered_map<std::string, std::string> decode_single_fix_msg(std::string& msg);

    std::pair<std::string, std::string> decode_single_tag_and_value(std::string& msg);
    void log_data() const;


};



#endif //FIXPARSER_H
