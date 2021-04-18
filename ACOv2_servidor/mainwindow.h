#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QListWidgetItem>
#include <QStandardItemModel>
#include <QBluetoothSocket>
#include <QBluetoothDeviceDiscoveryAgent>
#include "main_controller.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_pheromones_view();
signals:
    void messageReceived(const QString &sender, const QString &message);
private slots:
    void device_discovered(const QBluetoothDeviceInfo&);
    void when_connected();
    void when_disconnected();
    void on_scan_button_clicked();
    void on_bt_name_list_itemClicked(QListWidgetItem *item);
    void on_trasnmit_button_clicked();
    void on_clear_terminal_button_clicked();
    void on_close_button_clicked();
    void on_init_bot_button_clicked();
private:
    Ui::MainWindow *ui;
    QListWidgetItem *selected_;
    QStandardItemModel* model_ = new QStandardItemModel(6,6,this);
    Main_controller controller_;
    QBluetoothDeviceDiscoveryAgent *agent_ = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothSocket *socket_;
    QString string_address_;
    QString string_name_;
};
#endif // MAINWINDOW_H
