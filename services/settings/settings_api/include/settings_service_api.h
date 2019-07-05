#ifndef SETTINGS_SERVICE_API_H
#define SETTINGS_SERVICE_API_H

#include <QMap>
#include <QVariant>


#include "service.h"

namespace flt
{
namespace service
{
class SettingsServiceApiPrivate;
class SettingsServiceApi : public IService
{
    Q_DECLARE_PRIVATE(SettingsServiceApi)
    Q_OBJECT

public:
    ~SettingsServiceApi() override;

    static SettingsServiceApi* instance();

    using SettingsMap = QMap<QString, QVariant>;

    virtual QVariant value(const QString& key) const = 0;
    QVariant value(const QString& key, int num);
    bool boolValue(const QString& key, int num = 0);
    int intValue(const QString& key, int num = 0);
    double realValue(const QString& key, int num = 0);
    QString stringValue(const QString& key, int num = 0);

    virtual bool hasValue(const QString& key) const = 0;
    bool hasValue(const QString& key, int num) const;

public slots:
    virtual void setValue(const QString& key, const QVariant& value) = 0;
    void setValue(const QString& key, const QVariant& value, int num);

    virtual void remove(const QString& key) = 0;
    void remove(const QString& key, int num);

    virtual void clear() = 0;

    void addDefaultSettings(const SettingsMap& defaultSettings);
    void removeDefaultSettings(const SettingsMap& defaultSettings);
    void makeDefaults();

signals:
    void changed(const QString& key);

protected:
    SettingsServiceApi(SettingsServiceApiPrivate& dd, QObject* parent = nullptr);

    static SettingsServiceApi* m_instance;
};

} // namespace service
} // namespace flt

#define settings (flt::service::SettingsServiceApi::instance())

#endif // SETTINGS_SERVICE_API_H
