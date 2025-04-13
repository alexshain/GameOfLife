#ifndef MENUMODEL
#define MENUMODEL

#include "observable.h"

class MenuModel: public Observable {
    size_t iterations;
    std::string output_file;

public:
    void call();
    void setIterations(size_t iterations);
    void setOutputFile(const std::string& output_file);
    size_t getIterations() const;
    std::string getOutputFile() const;
};

#endif //MENUMODEL