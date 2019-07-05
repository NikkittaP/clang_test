#ifndef SERVICE_PRIVATE_H
#define SERVICE_PRIVATE_H

#include "service.h"

namespace
{
class Guard;
}

namespace flt
{
namespace service
{
class IServicePrivate
{
    Q_DECLARE_PUBLIC(IService)

public:
    virtual ~IServicePrivate();

    static ::Guard& guard();

    IService* q_ptr = nullptr;
};

} // namespace service
} // namespace flt

#endif // SERVICE_PRIVATE_H