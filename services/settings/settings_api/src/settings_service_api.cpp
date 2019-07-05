#include "settings_service_api.h"
#include "settings_service_api_p.h"

namespace
{
static const QString numSplitter = "_";

QString numerate(const QString& key, int num = 0)
{
    return num ? key + numSplitter + QString::number(num) : key;
}
} // namespace

using namespace flt;
using namespace flt::service;

SettingsServiceApi* SettingsServiceApi::m_instance = nullptr;

SettingsServiceApi::~SettingsServiceApi()
{
}

SettingsServiceApi* SettingsServiceApi::instance()
{
    return m_instance;
}

SettingsServiceApi::SettingsServiceApi(SettingsServiceApiPrivate& dd, QObject* parent) :
    IService(dd, parent)
{
}

QVariant SettingsServiceApi::value(const QString& key, int num)
{
    Q_D(SettingsServiceApi);

    QString numeratedKey = ::numerate(key, num);

    if (!hasValue(numeratedKey))
    {
        if (d->defaultSettings.contains(key))
        {
            setValue(numeratedKey, d->defaultSettings.value(key));
        }
    }

    return value(numeratedKey);
}

bool SettingsServiceApi::boolValue(const QString& key, int num)
{
    return value(key, num).toBool();
}

int SettingsServiceApi::intValue(const QString& key, int num)
{
    return value(key, num).toInt();
}

double SettingsServiceApi::realValue(const QString& key, int num)
{
    return value(key, num).toDouble();
}

QString SettingsServiceApi::stringValue(const QString& key, int num)
{
    return value(key, num).toString();
}

bool SettingsServiceApi::hasValue(const QString& key, int num) const
{
    return hasValue(::numerate(key, num));
}

void SettingsServiceApi::setValue(const QString& key, const QVariant& value, int num)
{
    setValue(::numerate(key, num), value);
}

void SettingsServiceApi::remove(const QString& key, int num)
{
    remove(::numerate(key, num));
}

void SettingsServiceApi::addDefaultSettings(const SettingsMap& defaultSettings)
{
    Q_D(SettingsServiceApi);
    for (const QString& key : defaultSettings.keys())
    {
        d->defaultSettings.insert(key, defaultSettings.value(key));
        if (hasValue(key)) continue;

        setValue(key, defaultSettings[key]);
    }
}

void SettingsServiceApi::removeDefaultSettings(const SettingsMap& defaultSettings)
{
    Q_D(SettingsServiceApi);
    for (const QString& key : defaultSettings.keys())
    {
        d->defaultSettings.remove(key);
    }
}

void SettingsServiceApi::makeDefaults()
{
    Q_D(SettingsServiceApi);
    clear();

    for (const QString& key : d->defaultSettings.keys())
    {
        setValue(key, d->defaultSettings[key]);
    }
}
