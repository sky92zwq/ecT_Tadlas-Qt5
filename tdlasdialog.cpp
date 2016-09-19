#include "tdlasdialog.h"
#include "ui_tdlasdialog.h"
#include <QDebug>

tdlasDialog::tdlasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tdlasDialog)
{
    ui->setupUi(this);

    ui->verticalLayout->setSizeConstraint(QLayout::SetFixedSize);

    ui->das_basefr_lab->setVisible(false);ui->das_basefr->setVisible(false);
    ui->das_duty_lab->setVisible(false);ui->das_duty->setVisible(false);
    ui->das_maxwl_lab->setVisible(false);ui->das_maxwl->setVisible(false);
    ui->das_minwl_lab->setVisible(false);ui->das_minwl->setVisible(false);
    ui->wms_basefr_lab->setVisible(false);ui->wms_basefr->setVisible(false);
    ui->wms_duty_lab->setVisible(false);ui->wms_duty->setVisible(false);
    ui->wms_maxwl_lab->setVisible(false);ui->wms_maxwl->setVisible(false);
    ui->wms_minwl_lab->setVisible(false);ui->wms_minwl->setVisible(false);
    ui->wms_sinam_lab->setVisible(false);ui->wms_sinam->setVisible(false);
    ui->wms_sinfr_lab->setVisible(false);ui->wms_sinfr->setVisible(false);
    lazerneedopen=true;
    ui->lazer1openclose->setText("O/C");
    ui->lazer2openclose->setText("O/C");
    ui->setlazer1tc->setText("设置温度");
    measure=null;
}

tdlasDialog::~tdlasDialog()
{
    delete ui;
}

void tdlasDialog::acceptusb(CS_ftfunction *u)
{
    usb=u;
    //qDebug()<<usb->status.at(usb->Open(0));
}



void tdlasDialog::on_lazer1openclose_clicked()
{
    if(lazerneedopen)
    {
        if(setlazeropen(0x1101)){

            ui->lazer1openclose->setText("O");
            lazerneedopen=false;
        }

    }
    else
    {
        if(setlazerclose(0x1102)){

            ui->lazer1openclose->setText("C");
            lazerneedopen=true;
        }

    }
    qDebug()<<lazerneedopen;
}


bool tdlasDialog::setlazeropen(quint16 lazer)
{
    if(usb->getnumDEv()&&usb->isopened()){
        QByteArray TxBuffer;//准备写入usb的发送命令
        QDataStream in(&TxBuffer, QIODevice::ReadWrite);
        in<<(quint16)lazer<<(quint16)0x0000;
        DWORD BytesReceived;//向下写入发送命令

        if(usb->Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4)
        {
            QString str="lazer open";
            emit mystatus(str);

            qDebug()<<BytesReceived;
            return true;
        }
        else
            return false;
    }
    else
    {
        QMessageBox::critical(NULL, "critical", "FT_device is not found or open",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
}

bool tdlasDialog::setlazerclose(quint16 lazer)
{
    if(usb->getnumDEv()&&usb->isopened()){
        QByteArray TxBuffer;//准备写入usb的发送命令
        QDataStream in(&TxBuffer, QIODevice::ReadWrite);
        in<<(quint16)lazer<<(quint16)0x0000;
        DWORD BytesReceived;//向下写入发送命令

        if(usb->Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4)
            {
            QString str="lazer close";
            emit mystatus(str);

            qDebug()<<BytesReceived;
            return true;
        }
        else
            return false;
    }
    else{
        QMessageBox::critical(NULL, "critical", "FT_device is not found or open",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
}


void tdlasDialog::on_setlazer1tc_clicked()
{

    if(usb->getnumDEv()&&usb->isopened()){
        if(lazerneedopen==false){

            QByteArray TxBuffer;//准备写入usb的发送命令
            QDataStream in(&TxBuffer, QIODevice::ReadWrite);
            quint8 floor=qFloor(ui->setlazer1tcbox->value());
            in<<(quint16)0x1111<<floor<<(quint8) (ui->setlazer1tcbox->value()-floor)*255;//double to dword??
            DWORD BytesReceived;//向下写入发送命令

            if(usb->Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4)
            {
            //emit lasersetting("lazer close");

            qDebug()<<BytesReceived;
            return ;
            }

        }
    }
    else{
        QMessageBox::critical(NULL, "critical", "FT_device is not found or open",
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return ;
    }

}


void tdlasDialog::on_das_clicked(bool checked)
{
    if(checked){
        ui->wms->setCheckState(Qt::Unchecked);


        ui->wms_basefr_lab->setVisible(false);ui->wms_basefr->setVisible(false);
        ui->wms_duty_lab->setVisible(false);ui->wms_duty->setVisible(false);
        ui->wms_maxwl_lab->setVisible(false);ui->wms_maxwl->setVisible(false);
        ui->wms_minwl_lab->setVisible(false);ui->wms_minwl->setVisible(false);
        ui->wms_sinam_lab->setVisible(false);ui->wms_sinam->setVisible(false);
        ui->wms_sinfr_lab->setVisible(false);ui->wms_sinfr->setVisible(false);

        ui->das_basefr_lab->setVisible(true);ui->das_basefr->setVisible(true);
        ui->das_maxwl_lab->setVisible(true);ui->das_maxwl->setVisible(true);
        ui->das_duty_lab->setVisible(true);ui->das_duty->setVisible(true);
        ui->das_minwl_lab->setVisible(true);ui->das_minwl->setVisible(true);
        measure=das;
    }
    else{
        ui->wms->setCheckState(Qt::Checked);

        ui->das_basefr_lab->setVisible(false);ui->das_basefr->setVisible(false);
        ui->das_duty_lab->setVisible(false);ui->das_duty->setVisible(false);
        ui->das_maxwl_lab->setVisible(false);ui->das_maxwl->setVisible(false);
        ui->das_minwl_lab->setVisible(false);ui->das_minwl->setVisible(false);

        ui->wms_basefr_lab->setVisible(true);ui->wms_basefr->setVisible(true);
        ui->wms_duty_lab->setVisible(true);ui->wms_duty->setVisible(true);
        ui->wms_maxwl_lab->setVisible(true);ui->wms_maxwl->setVisible(true);
        ui->wms_minwl_lab->setVisible(true);ui->wms_minwl->setVisible(true);
        ui->wms_sinam_lab->setVisible(true);ui->wms_sinam->setVisible(true);
        ui->wms_sinfr_lab->setVisible(true);ui->wms_sinfr->setVisible(true);
        measure=wms;
    }
}


void tdlasDialog::on_wms_clicked(bool checked)
{
    if(checked){
        ui->das->setCheckState(Qt::Unchecked);


        ui->das_basefr_lab->setVisible(false);ui->das_basefr->setVisible(false);
        ui->das_duty_lab->setVisible(false);ui->das_duty->setVisible(false);
        ui->das_maxwl_lab->setVisible(false);ui->das_maxwl->setVisible(false);
        ui->das_minwl_lab->setVisible(false);ui->das_minwl->setVisible(false);

        ui->wms_basefr_lab->setVisible(true);ui->wms_basefr->setVisible(true);
        ui->wms_duty_lab->setVisible(true);ui->wms_duty->setVisible(true);
        ui->wms_maxwl_lab->setVisible(true);ui->wms_maxwl->setVisible(true);
        ui->wms_minwl_lab->setVisible(true);ui->wms_minwl->setVisible(true);
        ui->wms_sinam_lab->setVisible(true);ui->wms_sinam->setVisible(true);
        ui->wms_sinfr_lab->setVisible(true);ui->wms_sinfr->setVisible(true);
        measure=wms;
    }
    else{
        ui->das->setCheckState(Qt::Checked);

        ui->das_basefr_lab->setVisible(true);ui->das_basefr->setVisible(true);
        ui->das_maxwl_lab->setVisible(true);ui->das_maxwl->setVisible(true);
        ui->das_duty_lab->setVisible(true);ui->das_duty->setVisible(true);
        ui->das_minwl_lab->setVisible(true);ui->das_minwl->setVisible(true);

        ui->wms_basefr_lab->setVisible(false);ui->wms_basefr->setVisible(false);
        ui->wms_duty_lab->setVisible(false);ui->wms_duty->setVisible(false);
        ui->wms_maxwl_lab->setVisible(false);ui->wms_maxwl->setVisible(false);
        ui->wms_minwl_lab->setVisible(false);ui->wms_minwl->setVisible(false);
        ui->wms_sinam_lab->setVisible(false);ui->wms_sinam->setVisible(false);
        ui->wms_sinfr_lab->setVisible(false);ui->wms_sinfr->setVisible(false);
        measure=das;
    }
}
void tdlasDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button == ui->buttonBox->button((QDialogButtonBox::Ok))){//如果点的是ok
        if(!lazerneedopen){//如果已经打开激光器

            if(ui->tab_2->isActiveWindow()){//如果在tab2
                //usb write
                if(ui->das->isChecked()){
                    //写入dasok
                    QByteArray TxBuffer;//准备写入usb的发送命令
                    QDataStream in(&TxBuffer, QIODevice::ReadWrite);
                    in<<(quint16)0x0101<<(quint16)0x0000;
                    DWORD BytesReceived;//向下写入发送命令

                    if(usb->Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4){
                        //emit lasersetting("lazer open");
                        qDebug()<<BytesReceived;
                    }

                    //写入das的参数8字节
                    TxBuffer.clear();
                    double bwfre = ui->das_basefr->value();
                    double bwdut = ui->das_duty->value();
                    double wlmax = ui->das_maxwl->value();
                    double wlmin = ui->das_minwl->value();

                    WORD frequency = 10000000 / bwfre;
                    WORD duty = frequency*bwdut;
                    WORD maximum = wlmax;
                    WORD minimum = wlmin;
                    WORD ratio = ((double)(maximum - minimum) / (double)duty)*(4096);

                    in<<frequency<<duty<<ratio<<minimum;

                    if(usb->Write(TxBuffer.data(),8,&BytesReceived)==FT_OK&&BytesReceived==8){
                        //emit
                        qDebug()<<"writedas canshu "<<BytesReceived;
                    }

                }
                if(ui->wms->isChecked()){
                    //写入wms ok
                    QByteArray TxBuffer;//准备写入usb的发送命令
                    QDataStream in(&TxBuffer, QIODevice::ReadWrite);
                    in<<(quint16)0x0201<<(quint16)0x0000;
                    DWORD BytesReceived;//向下写入发送命令

                    if(usb->Write(TxBuffer.data(),4,&BytesReceived)==FT_OK&&BytesReceived==4){
                        //emit lasersetting("lazer open");
                        qDebug()<<BytesReceived;
                    }
                    //准备写入wms的参数
                    TxBuffer.clear();
                    double fwfre  = ui->wms_basefr->value();
                    double fwduty = ui->wms_duty->value();
                    double fwlmax = ui->wms_maxwl->value();
                    double fwlmin = ui->wms_minwl->value();

                    double swlfreq = ui->wms_sinfr->value();
                    double swlampl = ui->wms_sinam->value();
                    //计算WMS各项参数
                    WORD fw_frequency = 10000000 / fwfre;
                    WORD fw_duty = fw_frequency*fwduty;
                    WORD fw_maximum = fwlmax;
                    WORD fw_minimum = fwlmin;
                    WORD fw_ratio = ((double)(fw_maximum - fw_minimum) / (double)fw_duty)*(4096); //放大了4096倍

                    WORD sw_frequency = 10000000 / swlfreq;
                    WORD sw_amplitude = swlampl;
                    WORD times = swlfreq / fwfre;

                    WORD swl[1024];
                    WORD num = 14 + 2 * sw_frequency;
                    for (int i = 0; i < sw_frequency; i++)
                    {
                        //采用四舍五入算法
                        swl[i] = (WORD)((swlampl* (abs(sinf((double)i/sw_frequency*2*M_PI))) )+0.5);
                    }

//                    //将WMS写入FPGA，使之进入WMS状态

//                    m_ftStatus = MYUSB_Write(TxBuffer, 4, &BytesWritten);

//                    //将WMS参数写入FPGA，设置激光器输出
//                    datatobuffer(TxBuffer, fw_frequency);
//                    datatobuffer(TxBuffer + 2, fw_duty);
//                    datatobuffer(TxBuffer + 4, fw_ratio);
//                    datatobuffer(TxBuffer + 6, fw_minimum);

//                    datatobuffer(TxBuffer + 8, sw_frequency);
//                    datatobuffer(TxBuffer + 10, sw_amplitude);
//                    datatobuffer(TxBuffer + 12, times);


//                    m_ftStatus = MYUSB_Write(TxBuffer, num, &BytesWritten);

                }
            }
        }
        else//没有打开laser
            QMessageBox::critical(NULL, "critical", "plz make sure laser is on",
                                  QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    }
}
