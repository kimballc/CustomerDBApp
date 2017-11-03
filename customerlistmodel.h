#ifndef CUSTOMERLISTMODEL_H
#define CUSTOMERLISTMODEL_H

#include <QAbstractListModel>
#include <vector>
#include "customer.h"

class CustomerListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CustomerListModel(std::vector<Customer> &customers, QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    //update - added reference member for access to the customers vector
    std::vector<Customer> &customers;
};

#endif // CUSTOMERLISTMODEL_H
