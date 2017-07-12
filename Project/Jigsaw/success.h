#ifndef SUCCESS_H
#define SUCCESS_H

#include <QDialog>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <QFontDatabase>
#include <QMessageBox>

#include "gamelogic.h"

namespace Ui {
class success;
}

class success : public QDialog
{
    Q_OBJECT

public:
    explicit success(QWidget *parent = 0);
    ~success();
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_sureButton_clicked();
    
    void setParameter(int gameTime,int gameStep,int answerStep);

    void newRecordFinishedSlot(QNetworkReply *reply);

private:
    Ui::success *ui;
    gameinfo* personal;
    
    QNetworkAccessManager *manager;
    
    std::vector<gameinfo> gameRecord;//历史游戏记录

    QString ButtonStyle = "QPushButton{background-color:#907B63;"

                            "color: white;   border-radius: 10px;  border: 2px groove gray;"

                            "border-style: outset;}"

                            "QPushButton:hover{background-color:white; color: black;}"

                            "QPushButton:pressed{background-color:rgb(85, 170, 255);"

                            "border-style: inset; }";
};

#endif // SUCCESS_H