#include "hello.h"

#include <taskflow/taskflow.hpp>
#include <iostream>
#include <QString>

Hello::Hello(QObject *parent) : QObject(parent) {
    // Constructor is empty
}

void Hello::runTaskFlow() {
    tf::Executor executor;
    tf::Taskflow taskflow;

    auto [A, B, C, D] = taskflow.emplace(
        [] () { std::cout << "TaskA\n"; return "Result A"; },
        [] () { std::cout << "TaskB\n"; return "Result B"; },
        [] () { std::cout << "TaskC\n"; return "Result C"; },
        [] () { std::cout << "TaskD\n"; return "Result D"; }
    );

    A.precede(B, C);
    D.succeed(B, C);

    executor.run(taskflow).wait();

    // Task is done, emit the signal with a result
    emit taskCompleted("任务完成 7");  // Replace with your actual result
}
