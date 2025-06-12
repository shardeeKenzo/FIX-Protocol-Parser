#include <iostream>
#include "Reader.h"
#include "FIXParser.h"
#include "LoggerCSV.h"

int main() {

    Reader reader;
    FIXParser parser;
    LoggerCSV logger_csv;

    std::deque<std::string> messages {};
    int i = 1;

    messages = reader.extractMessages("/home/shardee_/Projects/C++/FIX-Protocol-Parser/fix_messages.txt");

    for (std::string msg : messages) {
        std::unordered_map<std::string, std::string> map = parser.decode_single_fix_msg(msg);

        logger_csv.log_into_csv(static_cast<char>(i) + "mmmmmmmmmsg_log.csv", map);
        i++;
    }

    return 0;
}