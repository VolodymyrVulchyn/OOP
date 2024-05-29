#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <QObject>
#include <QAtomicInt>

class IdGenerator : public QObject {
    Q_OBJECT
public:
    static IdGenerator& getInstance() {
        static IdGenerator instance;
        return instance;
    }

    int getNextId() {
        return idCounter.fetchAndAddOrdered(1);
    }

private:
    QAtomicInt idCounter;

    explicit IdGenerator(QObject *parent = nullptr) : QObject(parent), idCounter(1) {}

    // Заборона копіювання та присвоєння для забезпечення Singleton
    IdGenerator(const IdGenerator&) = delete;
    IdGenerator& operator=(const IdGenerator&) = delete;
};

#endif // IDGENERATOR_H
