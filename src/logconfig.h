#ifndef LOGCONFIG_H
#define LOGCONFIG_H

#include <QString>

class LogConfig {


public:

    LogConfig(){}
    static LogConfig& getInstance() {
        static LogConfig inst;
        return inst;
    }

    bool printConsol() {
        return _printConsol;
    }

    bool thredName() {
        return _thredName;
    }

    QString filePath() {
        return _filePath;
    }

private:

    LogConfig(const LogConfig&)= delete;
    LogConfig& operator=(const LogConfig&)= delete;

    bool _printConsol{true};
    bool _thredName{true};
    QString _filePath{"./log.txt"};
};


#define gLogConfig LogConfig::getInstance

#endif // LOGCONFIG_H
