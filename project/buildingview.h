#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphicsviewzoom.h"

class BuildingView : public QGraphicsView
{
    Q_OBJECT
private:
    QList<QGraphicsScene> floorScenes;
    QBrush brushAllClearUnlocked = QBrush(Qt::blue, Qt::BrushStyle::SolidPattern);
    Graphics_view_zoom *graphicsViewZoom;
public:
    explicit BuildingView(QWidget *parent = nullptr);
    void setUpRooms();

signals:

public slots:
};

#endif // BUILDINGVIEW_H
