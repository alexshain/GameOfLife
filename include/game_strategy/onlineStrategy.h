#ifndef ONLINESTRATEGY
#define ONLINESTRATEGY

#include "gameStrategy.h"

class OnlineStrategy: public GameStrategy {
public:
    explicit OnlineStrategy(const std::string& input_file, const std::string& output_file, size_t iterations);
    void execute() override;
};

#endif //ONLINESTRATEGY