#ifndef OBSERVABLE
#define OBSERVABLE

#include "view/observer.h"
#include <vector>

class Observable {
    private:
        std::vector<Observer*> observers_;
    
    public:
        void addObserver(Observer* observer) {
            observers_.push_back(observer);
        }
    
        void notifyUpdate(std::string arg) {
            for(const auto& observer: observers_) {
                observer->update(arg);
            }
        }
    };

#endif //OBSERVABLE