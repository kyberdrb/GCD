#ifndef GCD_TESTRUNNER_H
#define GCD_TESTRUNNER_H


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


#endif //GCD_TESTRUNNER_H
