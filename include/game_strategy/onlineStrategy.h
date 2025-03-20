#ifndef ONLINESTRATEGY
#define ONLINESTRATEGY

#include "gameStrategy.h"

class OnlineStrategy: public GameStrategy {
public:
    OnlineStrategy(std::string input_file);
    void execute() const override;
};

#endif //ONLINESTRATEGY