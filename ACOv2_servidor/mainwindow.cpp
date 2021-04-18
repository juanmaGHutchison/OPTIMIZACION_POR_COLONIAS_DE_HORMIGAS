#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QFont font;
    font.setWeight(QFont::Bold);
    ui->setupUi(this);
    for(int i = 0; i < 6; i++) {
        model_->setHorizontalHeaderItem(i, new QStandardItem(QString::number(i)));
        model_->setVerticalHeaderItem(i, new QStandardItem(QString::number(i)));
    }
    ui->pheromones_table->horizontalHeader()->setFont(
                    font
                );
    ui->pheromones_table->verticalHeader()->setFont(
                    font
                );
    ui->pheromones_table->setModel(model_);
    ui->pheromones_table->setShowGrid(false);
    ui->Lpicture->setVisible(true);
    connect(    agent_,
                 SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
                 this,
                 SLOT(device_discovered(QBluetoothDeviceInfo))
            );
     agent_->start();
     socket_ = new QBluetoothSocket(
                 QBluetoothServiceInfo::RfcommProtocol
                 );
     connect(socket_,
             SIGNAL (disconnected()),
             this,
             SLOT (when_disconnected())
             );
     connect(socket_,
             SIGNAL (connected()),
             this,
             SLOT (when_connected())
             );
     QList<QStandardItem*> item;
     for(int i = 0; i < 6; i++)
         for(int j = 0; j < 6; j++) {
             item.append(
                             new QStandardItem(
                                 QString::number(controller_.matrix().pheromones_[i][j].resolv())
                             )
                         );

             model_->setItem(i, j, item[(i*6)+j]);
         }
     ui->pheromones_table->setModel(model_);
}
void MainWindow::device_discovered(const QBluetoothDeviceInfo& device) {
    ui->bt_name_list->addItem(
                device.address().toString() + "::" +  device.name()
                );
}
void MainWindow::when_connected() {
    ui->event_list->setEnabled(true);
    ui->clear_terminal_button->setEnabled(true);
    ui->connected_name_label->setText(string_name_);
    ui->trasnmit_button->setEnabled(true);
}
void MainWindow::when_disconnected() {
    ui->event_list->setEnabled(false);
    ui->connected_name_label->setText("No device connected");
    selected_->setSelected(false);
}
void MainWindow::update_pheromones_view() {
    QList<QStandardItem*> item;
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++) {
            item.append(
                            new QStandardItem(
                                QString::number(controller_.matrix().pheromones_[i][j].resolv())
                            )
                        );
            model_->setItem(i, j, item[(i*6)+j]);
        }
    ui->pheromones_table->setModel(model_);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_scan_button_clicked()
{
    selected_->setSelected(false);
    ui->bt_name_list->clear();
    socket_->disconnectFromService();
    agent_->stop();
    agent_->start();
}
void MainWindow::on_bt_name_list_itemClicked(QListWidgetItem *item)
{
    socket_->disconnectFromService();
    selected_ = item;
    selected_->setSelected(true);
    QString string = item->text();
    QStringList slist = string.split("::");
    string_address_ = slist[0];
    string_name_ = slist[1];
    static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
    socket_->connectToService(QBluetoothAddress(string_address_),
                             QBluetoothUuid(serviceUuid),
                             QIODevice::ReadWrite
                            );
}
void MainWindow::on_trasnmit_button_clicked()
{
    QByteArray line[10];
    QString path = "";
    QString aux = "";
    int i = 0;
    socket_->write("p");
    ui->event_list->addItem(string_name_ + " transmitting...");
    while(socket_->bytesAvailable() > 0) {
        qDebug() << socket_->isOpen();
        qDebug() << socket_->canReadLine();
        qDebug() << socket_->bytesToWrite();
        line[i] = socket_->readLine().trimmed();
        emit messageReceived(socket_->peerName(),
                             QString::fromUtf8(line[i].constData(), line[i].length()));
        ui->event_list->addItem(line[i]);
        path = line[0];
        i++;
        }
        if(!path.isEmpty()) {
            controller_.path_from_str(
                        QString::fromUtf8(line[0].constData(), line[0].length()
                    ));
            controller_.path().update_pheromones(
                        controller_.matrix()
                    );
            socket_->write(controller_.matrix().toString().toStdString().c_str());
            ui->event_list->addItem(controller_.matrix().toString().toStdString().c_str());
            path = "";
            for(int i = 0; i < 6; i ++) {
                for(int j = 0; j < 6; j++) {
                    aux += controller_.matrix().pheromones_[i][j].resolv();
                    aux += " ";
                }
                aux += "\n";
            }
        }
        qDebug() << aux;
        while(socket_->bytesAvailable() > 0) {
            i = 0;
            line[i] = socket_->readLine().trimmed();
            emit messageReceived(socket_->peerName(),
                                 QString::fromUtf8(line[i].constData(), line[i].length()));
        }
        update_pheromones_view();
        ui->event_list->addItem(string_name_ + " end of transmission.");
}
void MainWindow::on_clear_terminal_button_clicked()
{
    ui->event_list->clear();
}
void MainWindow::on_close_button_clicked()
{
    selected_->setSelected(false);
    ui->bt_name_list->clear();
    socket_->disconnectFromService();
    agent_->stop();
    agent_->start();
}
void MainWindow::on_init_bot_button_clicked()
{
    ui->event_list->addItem(string_name_ + " transmitting...");
    socket_->write(controller_.matrix().toString().toStdString().c_str());
    ui->event_list->addItem(controller_.matrix().toString().toStdString().c_str());
    ui->event_list->addItem(string_name_ + " end of transmission.");
}
