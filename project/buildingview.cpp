#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QGraphicsView(parent)
{
    // Set up Scenes
    for (int i = 0; i < totalFloorCount; i++)
    {
        floorScenes.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
    }
    currentSceneIndex = 0;
    currentScenePtr = floorScenes.first();
    setScene(currentScenePtr);

    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    graphicsViewZoom = new Graphics_view_zoom(this);
    graphicsViewZoom->set_modifiers(Qt::NoModifier);


    setUpRooms();

    show();
}

void BuildingView::setUpRooms()
{

    rooms.append(new Room(QRectF(-900/2, -900/2, 1800/2, 1800/2)));
    //floorScenes.at(0)->addItem(rooms.at(0));
    testDoor = new Door(true, (QRectF(-800/2, -900/2, 500/2, 200/2)), 0);
    floorScenes.at(0)->addItem(testDoor);

    testDoor2 = new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90);
    floorScenes.at(0)->addItem(testDoor2);

    testDoor3 = new Door(true, (QRectF(-900/2, -1000/2, 500/2, 200/2)), 45);
    floorScenes.at(0)->addItem(testDoor3);

    //rooms.append(new Room(QRectF(0, -900/2, 900/2, 1800/2)));
    //floorScenes.at(1)->addItem(rooms.at(1));
}

bool BuildingView::MapFloorUp()
{
    if (currentSceneIndex == totalFloorCount - 1)
    {
        return false;
    }

    currentSceneIndex += 1;
    currentScenePtr = floorScenes.at(currentSceneIndex);
    setScene(currentScenePtr);
    return true;
}

bool BuildingView::MapFloorDown()
{
    if (currentSceneIndex == 0)
    {
        return false;
    }

    currentSceneIndex -= 1;
    currentScenePtr = floorScenes.at(currentSceneIndex);
    setScene(currentScenePtr);
    return true;
}
