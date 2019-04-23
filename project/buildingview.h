#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphicsviewzoom.h"
#include "zone.h"


class BuildingView : public QGraphicsView
{
    Q_OBJECT
private:
    QBrush brushAllClearUnlocked = QBrush(Qt::blue, Qt::BrushStyle::SolidPattern);
    Graphics_view_zoom *graphicsViewZoom;
    QList<QGraphicsScene *> floorScenes;
    int currentSceneIndex;
    const int totalFloorCount = 2;
    QGraphicsScene *currentScenePtr;
    QList<Zone *> zones;
    QList<Room *> rooms;
    Door *testDoor;
    Door *testDoor2;
    Door *testDoor3;
    QGraphicsItem *selectedItem;
protected:
    //
public:
    explicit BuildingView(QWidget *parent = nullptr);
    void setUpRooms();
    Room* getSelectedRoom();

signals:
    void SelectionChanged();
public slots:
    bool MapFloorUp();
    bool MapFloorDown();
    void SceneSelectionChanged();
    QList<QGraphicsScene *> getMasterFloorScene();
private slots:

};

#endif // BUILDINGVIEW_H
