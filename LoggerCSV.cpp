//
// Created by shardee_ on 6/7/25.
//

#include "LoggerCSV.h"

#include <fstream>

std::string LoggerCSV::tagToString(const Tag tag) {
    return tagToStringMap[tag];
}

void LoggerCSV::log_into_csv(const std::string &filename, const std::unordered_map<std::string, std::string> &tags_and_values) {

    std::ofstream csv(filename);

    for (const std::pair<std::string, std::string> tag_and_value : tags_and_values) {
        int tag = std::stoi(tag_and_value.first);
        csv << tagToString(static_cast<Tag>(tag)) << tag_and_value.second << '\n';
    }
    csv.close();
}


