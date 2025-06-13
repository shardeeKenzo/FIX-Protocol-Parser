#include <iostream>
#include "Reader.h"
#include "FIXParser.h"
#include "LoggerCSV.h"

int main() {

    Reader reader;
    FIXParser parser;
    LoggerCSV logger_csv;

    std::ofstream csv("msg-fix-logs.csv");

    std::deque<std::string> messages {};

    messages = reader.extractMessages("/home/shardee_/Projects/C++/FIX-Protocol-Parser/fix_messages.txt");

    logger_csv.init_csv(csv);

    for (std::string msg : messages) {
        std::unordered_map<std::string, std::string> map = parser.decode_single_fix_msg(msg);

        logger_csv.log_into_csv(csv, map);
    }

    csv.close();

    return 0;
}