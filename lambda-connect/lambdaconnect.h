#ifndef _LAMBDA_CONNECT_H_
#define _LAMBDA_CONNECT_H_
#include <functional>
#include <QString>
#include <QObject>

class LambdaConnectorHelper: public QObject
{
    Q_OBJECT
public:
    LambdaConnectorHelper(QObject *parent, const char* signal,
                          const std::function<void()>& f,
                          Qt::ConnectionType type = Qt::AutoConnection);
    bool disconnect();
    bool connected();
public slots:
    void trigger();
private:
    bool m_result;
    const QString m_signal;
    std::function<void()> m_lambda;

};

LambdaConnectorHelper* connect(QObject *sender,
                               const char *signal,
                               const std::function<void()> &lambda,
                               Qt::ConnectionType type = Qt::AutoConnection);

#endif // _LAMBDA_CONNECT_H_


