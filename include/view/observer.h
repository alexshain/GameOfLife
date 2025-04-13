#ifndef OBSERVER
#define OBSERVER

#include <string>

class Observer {
    public:
        virtual void update(std::string arg) = 0;
        virtual ~Observer() = default;
    };

#endif //OBSERVER