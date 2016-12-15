#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString str ("/config.yaml");
    QString fileName(QApplication::applicationDirPath()+str);

    QFile file(fileName);


    if(file.open(QIODevice::ReadOnly)) {

       QTextStream in(&file);

       while(!in.atEnd()) {
          QString line = in.readLine();
          ui->yamlPre->appendPlainText(line);
       }
     file.close();
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insert_clicked()
{
        QStringList parts;
        YAML::Emitter out;
        out << YAML::BeginSeq;
        out << YAML::BeginMap;

        // time
            QString qTime=ui->time->text();
            std::string time=qTime.toUtf8().constData();
            out << YAML::Key << "time" << YAML::Value << time;
       // stand swing
            out << YAML::Key << "stand_swing" << YAML::Value;
            out << YAML::BeginMap;

            parts=ui->swingPos->text().split(",");
            std::vector <double> swingPos;
            for (unsigned int i=0;i<parts.length();i++)
                swingPos.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "position";
            out << YAML::Value << YAML::Flow <<swingPos ;

            parts=ui->swingRot->text().split(",");
            std::vector <double> swingRot;
            for (unsigned int i=0;i<parts.length();i++)
                swingRot.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "orientation" ;
            out << YAML::Value << YAML::Flow << swingRot;

            out << YAML::EndMap;

        // stand com

            out << YAML::Key << "stand_com" << YAML::Value;
            out << YAML::BeginMap;

            parts=ui->comPos->text().split(",");
            std::vector <double> comPos;
            for (unsigned int i=0;i<parts.length();i++)
                comPos.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "position";
            out << YAML::Value << YAML::Flow <<comPos ;

            parts=ui->comRot->text().split(",");
            std::vector <double> comRot;
            for (unsigned int i=0;i<parts.length();i++)
                comRot.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "orientation" ;
            out << YAML::Value << YAML::Flow << comRot;

            out << YAML::EndMap;

        // left hand

            parts=ui->leftHand->text().split(",");
            std::vector <double> leftHand;
            for (unsigned int i=0;i<parts.length();i++)
                leftHand.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "left_hand" ;
            out << YAML::Value << YAML::Flow << leftHand;

        // right hand

            parts=ui->rightHand->text().split(",");
            std::vector <double> rightHand;
            for (unsigned int i=0;i<parts.length();i++)
                rightHand.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "right_hand" ;
            out << YAML::Value << YAML::Flow << rightHand;

         out << YAML::EndMap;
         out<<YAML::EndSeq;

         QString qYamlPre=ui->yamlPre->toPlainText();

         QString qOut;
         if (ui->yamlPre->toPlainText()=="")
             qOut=out.c_str();
         else
           qOut=qYamlPre+"\n\n"+out.c_str();

         ui->yamlPre->setPlainText(qOut);

}

void MainWindow::on_create_clicked()
{

    QString str ("/config.yaml");
    QString fileName(QApplication::applicationDirPath()+str);

    QFile file(fileName);

    if ( file.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &file );
        QString qOut=ui->yamlPre->toPlainText();
        stream << qOut;
    }
}
