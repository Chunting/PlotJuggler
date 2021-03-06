#ifndef STATE_PUBLISHER_ROSTOPIC_H
#define STATE_PUBLISHER_ROSTOPIC_H

#include <QObject>
#include <QtPlugin>
#include <map>
#include <ros/ros.h>
#include <ros_type_introspection/ros_introspection.hpp>
#include "PlotJuggler/statepublisher_base.h"


class  TopicPublisherROS: public QObject, StatePublisher
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.icarustechnology.PlotJuggler.StatePublisher" "../statepublisher.json")
    Q_INTERFACES(StatePublisher)

public:
    TopicPublisherROS();
    virtual ~TopicPublisherROS();

    virtual void updateState(PlotDataMap* datamap, double current_time) override;
    virtual const char* name() const override { return "TopicPublisherROS"; }

    virtual bool enabled() const override { return enabled_; }

    void setParentMenu(QMenu *menu);

public slots:
    virtual void setEnabled(bool enabled) override;

private:
    std::map<std::string, ros::Publisher> publishers_;
    bool enabled_;
    ros::NodeHandlePtr _node;

    QAction* _current_time;
};

#endif // DATALOAD_CSV_H
