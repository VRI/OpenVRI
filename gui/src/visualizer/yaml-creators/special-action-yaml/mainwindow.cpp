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
       // left leg
            parts=ui->leftLeg->text().split(",");
            std::vector <double> leftLeg;
            for (unsigned int i=0;i<parts.length();i++)
                leftLeg.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "left_leg";
            out << YAML::Value << YAML::Flow <<leftLeg ;

      // right leg
            parts=ui->rightLeg->text().split(",");
            std::vector <double> rightLeg;
            for (unsigned int i=0;i<parts.length();i++)
                rightLeg.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "right_leg" ;
            out << YAML::Value << YAML::Flow << rightLeg;


      // left hand
            parts=ui->leftHand->text().split(",");
            std::vector <double> leftHand;
            for (unsigned int i=0;i<parts.length();i++)
                leftHand.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "left_leg";
            out << YAML::Value << YAML::Flow <<leftHand ;

     // right hand
            parts=ui->rightHand->text().split(",");
            std::vector <double> rightHand;
            for (unsigned int i=0;i<parts.length();i++)
                rightHand.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "right_hand" ;
            out << YAML::Value << YAML::Flow << rightHand;

        // head
            parts=ui->head->text().split(",");
            std::vector <double> head;
            for (unsigned int i=0;i<parts.length();i++)
                head.push_back(parts.value((i)).toDouble());

            out << YAML::Key << "head" ;
            out << YAML::Value << YAML::Flow << head;

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
