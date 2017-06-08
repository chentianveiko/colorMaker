#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>

class ColorMaker : public QObject
{
    Q_OBJECT
public:
    explicit ColorMaker(QObject *parent = 0);
    ~ColorMaker();

    Q_INVOKABLE GenerateAlgorithm algorithm() const;
    Q_INVOKABLE void setAlgorithm(GenerateAlgorithm algorithm);

signals:
    void colorChanged(const QColor & color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();
};

#endif // COLORMAKER_H
