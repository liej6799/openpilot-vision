
#include <iostream>
#include "models/dmonitoring.h"


int main() {

    // init the models
    DMonitoringModelState model;
    dmonitoring_init(&model);

    std::cout << "Hello World awd";
    return 0;
}

