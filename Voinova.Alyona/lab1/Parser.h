//
// Created by pikabol88 on 10/22/21.
//

#ifndef DAEMON_LAB_PARSER_H
#define DAEMON_LAB_PARSER_H

#include <string>
#include <map>
#include <list>
#include <vector>
#include <fstream>
#include <set>

class Parser {
public:
    class Grammar {
    public:
        enum ConfigParams{
            TIME_DELAY,
            DIRECTORY1,
            DIRECTORY2,
            DEFAULT,
        };

        Grammar();
        int getGrammarCount();
        ConfigParams getGrammarValue(std::string value);

    private:
        const std::map<std::string, ConfigParams> _grammar;

        Grammar(Grammar const&) = delete;
        Grammar & operator=(Grammar const&) = delete;
    };

    Parser() = default;
    static Parser& getInstance();
    bool parseConfig(std::string &configFileName);
    std::map<Parser::Grammar::ConfigParams, std::string> getParams();

private:
    static Parser _instance;

    std::map<Parser::Grammar::ConfigParams, std::string> _config;
    Grammar _grammar;

    Parser(Parser const&) = delete;
    Parser & operator=(Parser const&) = delete;
};
#endif //DAEMON_LAB_PARSER_H
