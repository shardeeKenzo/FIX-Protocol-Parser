#include <iostream>
#include "Reader.h"
#include "FIXParser.h"

int main() {

    Reader reader {"/home/shardee_/Projects/C++/FIX_Parser/fix_messages.txt"};
    FIXParser parser {};
    std::deque<std::string> messages {};

    messages = reader.extractMessages();

    for (std::string msg : messages) {
        std::unordered_map<std::string, std::string> map = parser.decode_single_fix_msg(msg);

        for (std::pair<std::string, std::string> pair : map) {
            std::cout << pair.first << "=" << pair.second << '\n';
        }
        std::cout << "-----------------------------------------------------" << '\n';
    }

    return 0;
}