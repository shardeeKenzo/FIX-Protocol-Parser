//
// Created by shardee_ on 6/4/25.
//

#include "FIXParser.h"

std::pair<std::string, std::string> FIXParser::decode_single_tag_and_value(std::string& msg) {

    const int pos = msg.find('=');

    std::string tag = msg.substr(0, pos);
    std::string value = msg.substr(pos + 1);

    return std::pair<std::string, std::string> {tag, value};

}


std::unordered_map<std::string, std::string> FIXParser::decode_single_fix_msg(std::string& msg) {

    int len = 0;
    int pos = 0;
    std::unordered_map<std::string, std::string> tags_and_values;

    for (const char c : msg) {
        len++;
        if (c == '|') {
            std::string s = msg.substr(pos, len - 1);
            tags_and_values.emplace(decode_single_tag_and_value(s));
            pos +=len;
            len = 0;
        }
    }

    return tags_and_values;
}

