//
// Created by shardee_ on 6/7/25.
//

#ifndef LOGGERCSV_H
#define LOGGERCSV_H
#include <string>
#include <unordered_map>

enum Tag {
    BeginString = 8,
    BodyLength = 9,
    CheckSum = 10,
    ClOrdID = 11,
    ExecID = 17,
    LastPx = 31,
    LastShares = 32,
    MsgType = 35,
    OrderQty = 38,
    OrdStatus = 39,
    OrigClOrdId = 41,
    Price = 44,
    SenderCompID = 49,
    Side = 54,
    Symbol = 55,
    TargetCompID = 56,
    TransactTime = 60,
    ExecType = 150,
};

class LoggerCSV {
private:
    std::unordered_map<Tag, std::string> tagToStringMap = {

        {BeginString, "BeginString: "},
        {BodyLength, "BodyLength: "},
        {CheckSum, "CheckSum: "},
        {ClOrdID, "ClOrdID: "},
        {ExecID, "ExecID: "},
        {LastPx, "LastPx: "},
        {LastShares, "LastShares: "},
        {MsgType, "MsgType: "},
        {OrderQty, "OrderQty: "},
        {OrdStatus, "OrdStatus: "},
        {OrigClOrdId, "OrigClOrdId: "},
        {Price, "Price: "},
        {SenderCompID, "SenderCompID: "},
        {Side, "Side: "},
        {Symbol, "Symbol: "},
        {TargetCompID, "TargetCompID: "},
        {TransactTime, "TransactTime: "},
        {ExecType, "ExecType: "}
    };

    std::string tagToString(Tag tag);

public:
    LoggerCSV() = default;

    void log_into_csv(const std::string& filename, const std::unordered_map<std::string, std::string>& tags_and_values);


};



#endif //LOGGERCSV_H
