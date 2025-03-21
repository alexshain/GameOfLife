#ifndef OFFLINESTRATEGY
#define OFFLINESTRATEGY

#include "gameStrategy.h"

class OfflineStrategy: public GameStrategy {
    size_t iterations;
    std::string output_file;

public:
    OfflineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations);
    void execute() const override;

private:
    void writeFile(const StateProcessor& processor) const;
};

#endif //OFFLINESTRATEGY