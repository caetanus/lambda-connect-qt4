#include "lambdaconnect.h"

LambdaConnectorHelper::LambdaConnectorHelper(QObject *parent,
                                             const char* signal,
                                             const std::function<void()>& f,
                                             Qt::ConnectionType type)
    : QObject(parent),
    m_signal(signal),
    m_lambda(f)
{
    m_result = QObject::connect(parent, signal, this, SLOT(trigger()), type);
}

void LambdaConnectorHelper::trigger()
{
    m_lambda();
}

bool LambdaConnectorHelper::connected()
{
    return m_result;
}

bool LambdaConnectorHelper::disconnect()
{
    if (m_result)
    {
        m_result = QObject::disconnect(parent(),
                                       m_signal.toAscii().data(),
                                       this,
                                       SLOT(trigger()));
    }
    return m_result;
}

LambdaConnectorHelper* connect(QObject *sender,
                        const char *signal,
                        const std::function<void()> &lambda,
                        Qt::ConnectionType type)
{
    return new LambdaConnectorHelper(sender, signal, lambda, type);
}
