#ifndef COLORMAKER_H
#define COLORMAKER_H

#include <QObject>
#include <QTimer>
#include <QColor>

class ColorMaker : public QObject
{
    Q_OBJECT

    // 声明可以被元对象访问的枚举类型: Q_ENUMS(枚举类型的名字)
    Q_ENUMS(generate)

    // 声明可以被元对象访问,修改的属性,并且在该属性发生变化时发射colorChanged信号
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QColor colorTime READ colorTime)

public:
    //枚举参数
    enum generate{
        randomRGB,
        randomRed,
        randomGreen,
        randomBlue,
        increase,
    };

private:
    QColor myColor;
    generate myAlgorithm;
    int mColorTimer;


public:
    explicit ColorMaker(QObject *parent = 0);
    ~ColorMaker();

    // Q_INVOKABLE放在类成员函数的返回类型前作为修饰,该函数就能被元对象调用了
    Q_INVOKABLE generate algorithm() const;
    Q_INVOKABLE void setAlgorithm(generate algorithm);
    Q_INVOKABLE QColor color() const;
    Q_INVOKABLE void setColor(QColor m_color);
    Q_INVOKABLE QColor colorTime() const;

protected:
    void timerEvent(QTimerEvent *e);

signals:
    void colorChanged(const QColor & color);
    void currentTime(const QString &strTime);

public slots:
    void start();
    void stop();
};

#endif // COLORMAKER_H
