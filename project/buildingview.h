#ifndef BUILDINGVIEW_H
#define BUILDINGVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "graphicsviewzoom.h"
#include "zone.h"
#include <QGraphicsItemGroup>


class BuildingView : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsItemGroup *doorsFloor1;

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
    QList<QGraphicsScene *> getMasterFloorScene();
    QGraphicsItemGroup *getFloor1();
    void masterLockdown();
    void masterUnlock();
    void clearAlarms();

signals:
    void SelectionChanged();
public slots:
    bool MapFloorUp();
    bool MapFloorDown();
    void SceneSelectionChanged();

private slots:

};

#endif // BUILDINGVIEW_H
