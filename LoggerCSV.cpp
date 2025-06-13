//
// Created by shardee_ on 6/7/25.
//

#include "LoggerCSV.h"

#include <fstream>

std::string LoggerCSV::tagToString(const Tag tag) {
    return tagToStringMap[tag];
}
void LoggerCSV::init_csv(std::ofstream &csv) {
    for (const std::pair<Tag, std::string> pair : tagToStringMap) {
        csv << tagToString(pair.first);
    }
    csv << '\n';
}


void LoggerCSV::log_into_csv(std::ofstream& csv, const std::unordered_map<std::string, std::string> &tags_and_values) {

    Message msg {};

    for (const std::pair<std::string, std::string> tag_and_value : tags_and_values) {
        switch (int int_tag = std::stoi(tag_and_value.first)) {
            case 8: msg.beginString = tag_and_value.second; break;
            case 9: msg.bodyLength = tag_and_value.second; break;
            case 10: msg.checkSum = tag_and_value.second; break;
            case 11: msg.clOrdID = tag_and_value.second; break;
            case 17: msg.execID = tag_and_value.second; break;
            case 31: msg.lastPx = tag_and_value.second; break;
            case 32: msg.lastShares = tag_and_value.second; break;
            case 35: msg.msgType = tag_and_value.second; break;
            case 38: msg.orderQty = tag_and_value.second; break;
            case 39: msg.ordStatus = tag_and_value.second; break;
            case 41: msg.origClOrdId = tag_and_value.second; break;
            case 44: msg.price = tag_and_value.second; break;
            case 49: msg.senderCompID = tag_and_value.second; break;
            case 54: msg.side = tag_and_value.second; break;
            case 55: msg.symbol = tag_and_value.second; break;
            case 56: msg.targetCompID = tag_and_value.second; break;
            case 60: msg.transactTime = tag_and_value.second; break;
            case 150: msg.execType = tag_and_value.second; break;
            default: break;
        }
    }

    csv << msg.beginString + ","
        << msg.bodyLength + ","
        << msg.checkSum + ","
        << msg.clOrdID + ","
        << msg.execID + ","
        << msg.lastPx + ","
        << msg.lastShares + ","
        << msg.msgType + ","
        << msg.orderQty + ","
        << msg.ordStatus + ","
        << msg.origClOrdId + ","
        << msg.price + ","
        << msg.senderCompID + ","
        << msg.side + ","
        << msg.symbol + ","
        << msg.targetCompID + ","
        << msg.transactTime + ","
        << msg.execType << '\n';
}


