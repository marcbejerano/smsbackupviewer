#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "smsmap.h"

#include <QMainWindow>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createActions();
    void createMenus();
    void loadSmsData(const QString& xmlFilename);
    void updateTitle(const QString& xmlFilename);
    void updateAddressListView();
    void updateChatView(const QString& address);

    Ui::MainWindow *ui;

    // Menubar
    QMenu* fileMenu;
    QAction* openAct;
    QAction* saveAct;
    QAction* printAct;
    QAction* quitAct;

    SmsMap smsMap;
    QMap<QString, QString> addressBook;
    QString currentAddress;

private slots:
    void open();
    void save();
    void print();
    void quit();
    void onAddressSelected(const QModelIndex& current, const QModelIndex& previous);
};
#endif // MAINWINDOW_H
