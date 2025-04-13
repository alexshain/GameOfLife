#ifndef OFFLINESTRATEGY
#define OFFLINESTRATEGY

#include "gameStrategy.h"

class OfflineStrategy: public GameStrategy {
public:
    OfflineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations);
    void execute() override;
};

#endif //OFFLINESTRATEGY