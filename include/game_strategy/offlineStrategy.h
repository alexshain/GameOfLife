#ifndef OFFLINESTRATEGY
#define OFFLINESTRATEGY

#include "gameStrategy.h"

class OfflineStrategy: public GameStrategy {
    size_t iterations_;
    std::string output_file_;

public:
    OfflineStrategy(std::string input_file, std::string output_file, size_t iterations);
    void execute() const override;

private:
    void writeFile(const StateProcessor& processor) const;
};

#endif //OFFLINESTRATEGY