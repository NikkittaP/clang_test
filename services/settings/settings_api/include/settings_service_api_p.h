#ifndef SETTINGS_SERVICE_API_P_H
#define SETTINGS_SERVICE_API_P_H

#include <QMap>
#include <QVariant>


#include "service_p.h"
#include "settings_service_api.h"

namespace flt
{
namespace service
{
class SettingsServiceApiPrivate : public IServicePrivate
{
    Q_DECLARE_PUBLIC(SettingsServiceApi)
public:
    SettingsServiceApi::SettingsMap defaultSettings;
};

} // namespace service
} // namespace flt

#endif // SETTINGS_SERVICE_API_P_H
