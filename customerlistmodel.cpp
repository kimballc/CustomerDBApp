#include "customerlistmodel.h"

CustomerListModel::CustomerListModel(std::vector<Customer> &customers, QObject *parent)
    : QAbstractListModel(parent), customers(customers)
{
}

int CustomerListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    else
        return customers.size();

    // FIXME: Implement me!
}

QVariant CustomerListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    // ADDED - CustomerListModel's data manager serves several roles, the most
    // important of which is to display the data in its companion widget. If
    // that's the role it's currently exercising, it will do display the current
    // customer's last name followed by first name.
    if (role==Qt::DisplayRole)
    {
        std::string displayName = customers.at(index.row()).getLastName() + ", "
                + customers.at(index.row()).getFirstName();
        return QVariant(QString::fromStdString(displayName));
    }

    // FIXME: Implement me!
    return QVariant();
}
