#pragma once

#include "ConfigParser.h"
#include "Logger.h"

class DaemonGrammar : public Grammar {
private:
    static std::vector<std::string> const tokens;

public:
    DaemonGrammar() : Grammar(tokens) {}

};

class Daemon {
private:
    enum TOKENS {
        DIR_IN = 0,
        DIR_OUT,
        REPEAT_SIZE,
    };

private:
    static std::string const pid_file;
    static bool terminate;
    static bool reread;

    Grammar grammar;
    std::string const cfg;
    Logger logger;

    std::string dir_in;
    std::string dir_out;
    size_t repeat_time;
    std::string output_filename = "total.log";
    std::string extension = ".log";
    bool first_line = true;

public:
    explicit Daemon(std::string const& config);
    ~Daemon();

    int run();

private:
    static void signal_handler(int signal_id);
    static void need_to_terminate();
    static void need_to_reread_congif();

    void parse_tokens(std::vector<ConfigParser::Token> const& tokens);

    pid_t executing_pid() const;
    int create_pid_file() const;
    void setup_handler() const;

    int reread_congig();

    int init();

    int work();
    char* file_content(std::string const& filename) const;

    Daemon() = delete;
};
