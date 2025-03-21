#ifndef ONLINESTRATEGY
#define ONLINESTRATEGY

#include "gameStrategy.h"

class OnlineStrategy: public GameStrategy {
public:
    explicit OnlineStrategy(const std::string& input_file);
    void execute() const override;
};

#endif //ONLINESTRATEGY