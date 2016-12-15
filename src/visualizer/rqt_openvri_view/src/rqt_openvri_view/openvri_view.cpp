#include <rqt_openvri_view/openvri_view.h>
#include <QCheckBox>
#include <ros/package.h>

namespace rqt_openvri_view {

OpenVriView::OpenVriView() : rqt_gui_cpp::Plugin(), widget(0) {

    std::stringstream configPathString;
    std::string path = ros::package::getPath("rqt_openvri_view");
    setObjectName("OpenVriView");
}

void OpenVriView::initPlugin(qt_gui_cpp::PluginContext& context) {
    widget = new QMainWindow();
    ui.setupUi(widget);
    context.addWidget(widget);
    widget->setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint);

    paramettuner = new Parametertuner(getNodeHandle());
    ui.tabWidget->addTab(paramettuner,"ParameterTuner");
}
} // namespace

PLUGINLIB_DECLARE_CLASS(rqt_openvri_view, OpenVriView, rqt_openvri_view::OpenVriView, rqt_gui_cpp::Plugin)

