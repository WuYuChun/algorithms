#include <iostream>
#include "unit_test.h"

#include <glog/logging.h>

using namespace std;

int main( int argc , char *argv[])
{
    google::InitGoogleLogging(argv[0]);
    LOG(INFO) << "hhhh";
    std::cout << "===============================================================" << std::endl;
    testFunc1();
    std::cout << "===============================================================" << std::endl;
    testFunc2();
    std::cout << "===============================================================" << std::endl;
    testFunc3();
    std::cout << "===============================================================" << std::endl;
    testFunc4();
    std::cout << "===============================================================" << std::endl;
    testFunc5();
    std::cout << "===============================================================" << std::endl;
    testFunc6();
    std::cout << "===============================================================" << std::endl;
    testFunc7();
    std::cout << "===============================================================" << std::endl;
    testFunc8();
    std::cout << "===============================================================" << std::endl;
    return 0;
}
