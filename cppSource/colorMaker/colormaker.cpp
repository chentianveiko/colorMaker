#include "colormaker.h"
#include <QDateTime>
#include <QTimerEvent>

ColorMaker::ColorMaker(QObject *parent) : QObject(parent)
  ,myColor(Qt::black)
  ,myAlgorithm(randomRGB)
  ,mColorTimer(0)
{
    qsrand(QDateTime::currentDateTime().toTime_t());
}

ColorMaker::~ColorMaker()
{

}

ColorMaker::generate ColorMaker::algorithm() const
{
    return myAlgorithm;
}

void ColorMaker::setAlgorithm(ColorMaker::generate algorithm)
{
    myAlgorithm = algorithm;
}

QColor ColorMaker::color() const
{
    return myColor;
}

void ColorMaker::setColor(QColor m_color)
{
    myColor = m_color;
}

QColor ColorMaker::colorTime() const
{
    QTime time = QTime::currentTime();
    int r = time.hour();
    int g = time.minute()*2;
    int b = time.second()*4;

    return QColor::fromRgb(r, g, b);
}

void ColorMaker::timerEvent(QTimerEvent *e)
{
    if(e->timerId() == mColorTimer){
        switch (myAlgorithm) {
        case randomRGB:
            myColor.setRgb(qrand()%255, qrand()%255, qrand()%255);
            break;

        case randomRed:
            myColor.setRed(qrand() % 255);
            break;

        case randomGreen:
            myColor.setGreen(qrand() % 255);
            break;

        case randomBlue:
            myColor.setBlue(qrand() % 255);
            break;

        case increase:
            int r = myColor.red() + 10;
            int g = myColor.green() + 10;
            int b = myColor.blue() + 10;
            myColor.setRgb(r%255,g%255,b%255);
            break;
        }

        emit colorChanged(myColor);
        emit currentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    }else{
        QObject::timerEvent(e);
    }
}

void ColorMaker::start()
{
    if(mColorTimer == 0){
        mColorTimer = startTimer(1000);
    }
}

void ColorMaker::stop()
{
    if(mColorTimer > 0){
        killTimer(mColorTimer);
        mColorTimer = 0;
    }
}

