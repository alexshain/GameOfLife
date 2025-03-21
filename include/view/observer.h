#ifndef OBSERVER
#define OBSERVER

class Observer {
    public:
        virtual void update() = 0;
        virtual ~Observer() = default;
    };

#endif //OBSERVER