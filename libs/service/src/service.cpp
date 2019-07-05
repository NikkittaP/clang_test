#include "service.h"

#include "service_p.h"
#include <QtDebug>

#include <algorithm>

using namespace flt::service;

namespace
{
class Guard
{
public:
    void append(IService* service)
    {
        m_serviceList << service;
    }

    ~Guard()
    {
        std::reverse(m_serviceList.begin(), m_serviceList.end());
        for (auto service : m_serviceList)
        {
            delete service;
        }
    }
    QVector<IService*> m_serviceList;
};
} // namespace

IService::IService(IServicePrivate& dd, QObject* parent) : QObject(parent), d_ptr(&dd)
{
    d_ptr->q_ptr = this;
    d_ptr->guard().append(this);
}

IService::~IService()
{
}

IServicePrivate::~IServicePrivate()
{
}

::Guard& IServicePrivate::guard()
{
    static ::Guard guard;
    return guard;
}

bool IService::init()
{
    return true;
}
