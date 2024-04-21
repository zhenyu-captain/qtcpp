#ifndef HELLO_H
#define HELLO_H

#include <QObject>
#include <QString>

class Hello : public QObject {
    Q_OBJECT

public:
    explicit Hello(QObject *parent = nullptr);

signals:
    void taskCompleted(const QString &result);

public slots:
    void runTaskFlow();
};

#endif // HELLO_H
