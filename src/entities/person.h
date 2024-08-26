#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QHash>
#include <QVariant>
#include <memory>

#include "entity_interface.h"
#include "income_period.h"

class Person : public EntityInterface {
public:
    static QString name;
    static std::vector<QString> fields;

    Person();
    QString entityName() const override;
    EntityType entityType() const override;
    std::vector<QString> entityFields() const override;
    void setData(QString field, QVariant val) override;
    void setIncomePeriod(std::shared_ptr<IncomePeriod> period);
    const int getId() const override;
    QHash<QString, QVariant> getData(int role = 0) const override;
    QVariant getData(QString field, int role = 0) const override;
    std::shared_ptr<IncomePeriod> getIncomePeriod() const;
private:
    int m_id;
    QString m_name;
    double m_income;
    std::shared_ptr<IncomePeriod> m_incomePeriod;
};

#endif // PERSON_H
