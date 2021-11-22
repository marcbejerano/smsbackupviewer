#include "helper.h"
#include "mainwindow.h"
#include "multimediamessage.h"
#include "smscollection.h"
#include "textmessage.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QImage>
#include <QImageWriter>
#include <QSlider>
#include <QSpinBox>
#include <QStringListModel>


const QString cssDateBreak = "style=\"background-color:#555555;border-bottom:1px;border-style:solid;border-color:#ffffff;text-align:center;\"";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions() {
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a SMS Backup/Restore XML file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save..."), this);
    saveAct->setShortcuts(QKeySequence::SaveAs);
    saveAct->setStatusTip(tr("Save one or more chats"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print one or more chats"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit application"));
    connect(quitAct, &QAction::triggered, this, &MainWindow::quit);
}

void MainWindow::createMenus() {
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);
}

void MainWindow::loadSmsData(const QString& xmlFilename) {
    QFile xmlFile(xmlFilename);
    ui->statusbar->showMessage("Importing " + xmlFile.fileName());
    SmsCollection smses = SmsCollection::read(xmlFile);
    smsMap = SmsMap::fromCollection(smses);
    ui->statusbar->showMessage(QString("Import complete. %1 messages loaded").arg(smses.getCount()));

    // build the addressbook
    addressBook.clear();
    for (auto ix = smses.getMessages().cbegin(); ix != smses.getMessages().cend(); ix++) {
        Message* m = *ix;
        if (m->getContactName() == nullptr) continue;
        if (addressBook.contains(m->getAddress())) continue;
        addressBook.insert(m->getAddress(), m->getContactName());
    }
}

void MainWindow::updateTitle(const QString &xmlFilename) {
    QString fileName = xmlFilename;
    fileName.remove(0, fileName.lastIndexOf("/") + 1);
    setWindowTitle(fileName);
}

void MainWindow::updateAddressListView() {
    QStringList addressList;
    for (auto ix = smsMap.keys().cbegin(); ix != smsMap.keys().cend(); ++ix) {
        QString address = *ix;
        if (addressBook.contains(address)) {
            const QString contact = addressBook[address];
            address.append(" ").append(contact);
        }
        addressList << address;
    }

    QStringListModel *model = new QStringListModel(this);
    model->setStringList(addressList);
    ui->addressListView->setModel(model);
    ui->addressListView->setSelectionMode(QAbstractItemView::SingleSelection);

    QItemSelectionModel *selectionModel = ui->addressListView->selectionModel();
    selectionModel->clearSelection();
    connect(selectionModel, SIGNAL(currentRowChanged(QModelIndex, QModelIndex)), this, SLOT(onAddressSelected(QModelIndex, QModelIndex)));
}


void MainWindow::updateChatView(const QString& address) {
    if (currentAddress == address) return;
    currentAddress = address;

    ui->textEdit->clear();

    QString html;
    QDate lastDay(0, 0, 0);
    QList<Message*>* msgs = smsMap[address];

    for (auto ix = msgs->cbegin(); ix != msgs->cend(); ix++) {
        const QDateTime dt = QDateTime::fromMSecsSinceEpoch((*ix)->getDate());
        const QString ds = dt.toString("yyyy-MM-dd");
        QDate ddt = dt.date();

        if (lastDay.year() == 0 || lastDay.daysTo(ddt) >= 1) {
            lastDay = ddt;
            html.append("<div ").append(cssDateBreak).append(">").append(ds).append("</div>");
        }

        html.append(Helper::formatMessageForHtml(*ix));
    }

    ui->textEdit->setHtml(html);
}

void MainWindow::open() {
    QFileDialog dialog(this);
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("SMS Backup/Restore XML Files(*.xml)"));
    dialog.setReadOnly(true);
    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
        if (fileNames.size() == 1) {
            loadSmsData(fileNames.first());
            updateTitle(fileNames.first());
            updateAddressListView();
        }
    }
}


void MainWindow::save() {
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) SmsMap::save(smsMap, currentAddress, dir);
}

void MainWindow::print() {
    // maybe in the future?
}

void MainWindow::quit() {
    close();
}

void MainWindow::onAddressSelected(const QModelIndex& current, const QModelIndex& previous) {
    Q_UNUSED(previous)
    QString address = current.data(Qt::DisplayRole).toString();
    address.truncate(address.indexOf(" "));
    updateChatView(address);
}
