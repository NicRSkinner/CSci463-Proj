#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphicsviewzoom.h"
#include "room.h"

class BuildingView : public QGraphicsView
{
    Q_OBJECT
private:
    QBrush brushAllClearUnlocked = QBrush(Qt::blue, Qt::BrushStyle::SolidPattern);
    Graphics_view_zoom *graphicsViewZoom;
    QList<QGraphicsScene *> floorScenes;
    int currentSceneIndex;
    int totalFloorCount = 2;
    QGraphicsScene *currentScenePtr;
    QList<Room *> rooms;
protected:
    //
public:
    explicit BuildingView(QWidget *parent = nullptr);
    void setUpRooms();

signals:

public slots:
    bool MapFloorUp();
    bool MapFloorDown();
};

#endif // BUILDINGVIEW_H
