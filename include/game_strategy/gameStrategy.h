#ifndef GAMESTRATEGY
#define GAMESTRATEGY

#include "model/stateProcessor.h"

using st_prcsr::StateProcessor;

class GameStrategy {
protected:
    std::string input_file;
    size_t iterations;
    std::string output_file;

public:
    explicit GameStrategy(const std::string& input_file, const std::string& output_file, size_t iterations);
    virtual void execute() = 0;
    virtual ~GameStrategy() = default;

protected:
    void writeFile(const StateProcessor& processor) const;
};

#endif //GAMESTRATEGY