#pragma once

class TestRunner {
private:
    bool testsRun = false;
    int testStatus;
public:
    explicit TestRunner(char *runTestsArg);

    bool shouldRunTests(char* argument);
    int runTestSuite();
    void allTestsHaveRun();
    bool wereAllTestsRun();
    int getTestStatus();
};
