#ifndef openvri_VIEW_H
#define openvri_VIEW_H

// ROS Headers
#include <ros/ros.h>
#include <rqt_gui_cpp/plugin.h>
#include <pluginlib/class_list_macros.h>

// QT Headers
#include <QWidget>
#include <QMouseEvent>
#include <QStringListModel>
#include <QMessageBox>
#include <QMutex>
#include <QStringList>
#include <QPen>
#include <QColor>
#include <QMessageBox>
#include <QPainter>
#include <ui_openvri_view.h>

// Messages
#include <geometry_msgs/Point.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Float64.h>
#include <QMainWindow>
#include <vector>
#include <bitset>


#include <rqt_openvri_view/parametertuner.h>

using namespace parametertuner;

namespace rqt_openvri_view {

class OpenVriView
        : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    OpenVriView();
    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    Ui::MainWindow ui;
    QMainWindow* widget;
    Parametertuner* paramettuner;
    ros::NodeHandle nh_;
    ros::Subscriber sub;

};
} // namespace
#endif // my_namespace__my_plugin_H
