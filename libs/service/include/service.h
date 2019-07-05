#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshadow-field"
#pragma clang diagnostic ignored "-Wunused-template"

namespace flt
{
namespace service
{
class IServicePrivate;
class IService : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(IService)
    Q_DISABLE_COPY(IService)

public:
    ~IService() override;

protected:
    IService(IServicePrivate& dd, QObject* parent = nullptr);

    virtual bool init();

    QScopedPointer<IServicePrivate> d_ptr;
};

template<class T, typename... Args>
inline static bool initService(Args&&... args)
{
    static_assert(std::is_base_of<IService, T>::value,
                  "ServiceApi class must be derived from IService interface\n");
    return T::creator(std::forward<Args>(args)...);
}
} // namespace service
} // namespace flt

#pragma clang diagnostic pop
#endif // SERVICE_H