#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QObject>
#include <QWidget>
#include "qgraphicsview.h"
#include "qgraphicsscene.h"
#include "qgraphicsitem.h"
#include <QList>
#include "graphicsviewzoom.h"


class BuildingView : public QWidget
{
    Q_OBJECT
public:
    explicit BuildingView(QWidget *parent = nullptr);
    BuildingView(QGraphicsView *gv, QWidget *parent = nullptr);
signals:

public slots:

private:
    QGraphicsView *graphicsViewMap;
    QList<QGraphicsScene> sceneList;
    QGraphicsScene *currentScene;
    Graphics_view_zoom *zoom;

};

#endif // BUILDINGVIEW_H
