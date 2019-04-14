#include <cstring>
#include <gtest/gtest.h>
#include "TestRunner.h"

TestRunner::TestRunner(char *runTestsArg) {
    if (shouldRunTests(runTestsArg)) {
        allTestsHaveRun();
        this->testStatus = runTestSuite();
    }
}

void TestRunner::allTestsHaveRun() {
    this->testsRun = true;
}

bool TestRunner::shouldRunTests(char* argument) {
    return argument != nullptr && (strncmp(argument, "--test", 6) == 0);
}

int TestRunner::runTestSuite() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

bool TestRunner::wereAllTestsRun() {
    return this->testsRun;
}

int TestRunner::getTestStatus() {
    return this->testStatus;
}
