#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QGraphicsView(parent)
{
    // Set up Scenes
    for (int i = 0; i < totalFloorCount; i++)
    {
        floorScenes.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
        connect(floorScenes.at(i), SIGNAL(selectionChanged()), this, SLOT(SceneSelectionChanged())); //connect the signal from the scene for when a selection is changed and use it to update ours
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

void BuildingView::SceneSelectionChanged()
{
    int selectedCount = currentScenePtr->selectedItems().count();
    if (selectedCount == 1)
    {
        selectedItem = currentScenePtr->selectedItems().at(0);
    }
    else if (selectedCount == 0)
    {
        selectedItem = nullptr;
    }
    emit SelectionChanged();

}

Room* BuildingView::getSelectedRoom()
{
    // We're only able to select rooms on screen, so this cast should work
    return dynamic_cast<Room *>(selectedItem);
}

void BuildingView::setUpRooms()
{

    rooms.append(new Room(QRectF(-900/2, -900/2, 1800/2, 1800/2)));
    floorScenes.at(0)->addItem(rooms.at(0));
    rooms.append(new Room(QRectF(-1500/2, -2500/2, 1800/2, 1800/2)));
    floorScenes.at(0)->addItem(rooms.at(1));

    testDoor = new Door(true, (QRectF(-800/2, -800/2, 500/2, 200/2)), 0, rooms.at(0));
    floorScenes.at(0)->addItem(testDoor);
    rooms.at(0)->addDoor(testDoor);

    testDoor2 = new Door(true, (QRectF(-900/2, -900/2, 500/2, 200/2)), 90, rooms.at(0));
    floorScenes.at(0)->addItem(testDoor2);
    rooms.at(0)->addDoor(testDoor2);

    testDoor3 = new Door(true, (QRectF(1000/2, -1500/2, 500/2, 200/2)), -90, rooms.at(1));
    floorScenes.at(0)->addItem(testDoor3);
    rooms.at(1)->addDoor(testDoor3);

    //rooms.append(new Room(QRectF(0, -900/2, 900/2, 1800/2)));
    //floorScenes.at(1)->addItem(rooms.at(1));
}

bool BuildingView::MapFloorUp()
{
    if (currentSceneIndex == totalFloorCount - 1)
    {
        return false;
    }
    currentScenePtr->clearSelection();
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
    currentScenePtr->clearSelection();
    currentSceneIndex -= 1;
    currentScenePtr = floorScenes.at(currentSceneIndex);
    setScene(currentScenePtr);
    return true;
}
